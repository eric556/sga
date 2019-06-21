#include "ComponentRegister.h"
#include "Display.h"
#include "Input.h"
#include "KineticBody.h"
#include "Transform.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "TileMap.h"
#include "BoundingBox.h"
#include "Camera.h"
#include <sol.hpp>
#include <iostream>

namespace Components {

	void ComponenetRegister::RegisterComponents(Lua::LuaInstance& instance)
	{
		auto displayType = instance.registerComponent<Display>("Display");
		displayType.set("shape", &Components::Display::shape);

		auto inputType = instance.registerComponent<Input>("Input");
		inputType.set("speed", &Components::Input::speed);

		auto kineticBody = instance.registerComponent<KineticBody>("KineticBody");
		kineticBody.set("velocity", &Components::KineticBody::velocity);
		kineticBody.set("acceleration", &Components::KineticBody::acceleration);
		kineticBody.set("forceAccumulator", &Components::KineticBody::forceAccumulator);
		kineticBody.set("mass", &Components::KineticBody::mass);

		auto transformType = instance.registerComponent<Transform>("Transform");
		transformType.set("position", &Components::Transform::position);
		transformType.set("scale", &Components::Transform::scale);
		transformType.set("rotation", &Components::Transform::rotation);

		auto textureType = instance.registerComponent<Sprite>("Sprite");
		textureType.set("texture_id", &Components::Sprite::id);
		textureType.set("useTextureRect", &Components::Sprite::useTextureRect);
		textureType.set("textureRect", &Components::Sprite::textureRect);

		auto animatedSpriteType = instance.registerComponent<AnimatedSprite>("AnimatedSprite");
		animatedSpriteType.set("texture_id", &Components::AnimatedSprite::id);
		animatedSpriteType.set("currentAnimation", &Components::AnimatedSprite::currentAnimation);
		animatedSpriteType.set_function("setCurrentAnimation", &Components::AnimatedSprite::setCurrentAnimation);
		animatedSpriteType.set("currentAnimationFrame", &Components::AnimatedSprite::currentAnimationFrame);
		animatedSpriteType.set("sprite", &Components::AnimatedSprite::sprite);
		animatedSpriteType.set_function("setAnimations", [](AnimatedSprite& self, sol::table anims) {
			for (const auto& key_value_pair : anims) {
				std::string name = key_value_pair.first.as<std::string>();
				sol::table animationTable = key_value_pair.second.as<sol::table>();
				std::vector<Frame> frames;
				for (const auto& framePair : animationTable) {
					auto frameTable = framePair.second.as<sol::table>();
					Frame frame;
					frame.x = frameTable.get<sol::table>("frame").get<int>("x");
					frame.y = frameTable.get<sol::table>("frame").get<int>("y");
					frame.width = frameTable.get<sol::table>("frame").get<int>("width");
					frame.height = frameTable.get<sol::table>("frame").get<int>("height");
					frame.time = frameTable.get<float>("time");
					frames.push_back(frame);
				}
				self.setAnimation(name, frames);
			}
		});


		auto tilemapType = instance.registerComponent<TileMap>("Tilemap");
		tilemapType.set("tilesetId", &TileMap::tilesetId);
		tilemapType.set_function("setMap", [](TileMap& self, sol::table tilemap, std::vector<sol::table> tiledefs, int indexOffset) {
			sol::table layers = tilemap["layers"];
			int width = tilemap["width"];
			int height = tilemap["height"];

			std::map<int, std::vector<std::vector<Tile>>> tileLayers;

			for (const auto& layer : layers) {
				std::string name = layer.first.as<std::string>();
				sol::table layerTable = layer.second;
				int zIndex = layerTable.get<int>("zIndex");
				std::vector<std::vector<int>> tile_indicies = layerTable.get<std::vector<std::vector<int>>>("data");

				std::vector<std::vector<Tile>> tiles;
				for (int y = 0; y < height; y++) {
					std::vector<Tile> row;
					for (int x = 0; x < width; x++) {
						int index = tile_indicies[y][x]  + indexOffset;
						sol::table tile = tiledefs[(index < 0)?0:index];
						row.push_back({ tile.get<int>("x"), tile.get<int>("y"), tile.get<int>("width"), tile.get<int>("height") });
					}
					tiles.push_back(row);
				}
				tileLayers[zIndex] = tiles;
			}

			self.setMap(width, height, tileLayers);
		});

		auto boundingBoxType = instance.registerComponent<BoundingBox>("BoundingBox");
		boundingBoxType.set("rect", &BoundingBox::boundingBox);

		auto cameraType = instance.registerComponent<Camera>("Camera");
		cameraType.set_function("setSize", [](Camera& self, int width, int height) {
			self.view.setSize(width, height);
		});
		// cameraType.set("followEntity", &Camera::followEntity);
		cameraType.set_function("setFollow", [](Camera& self, std::shared_ptr<ECS::Entity>& entity) {
			self.followEntity = entity;
		});
	}
}