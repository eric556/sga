#include "ComponentRegister.h"
#include "Display.h"
#include "Input.h"
#include "KineticBody.h"
#include "Transform.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
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
	}
}