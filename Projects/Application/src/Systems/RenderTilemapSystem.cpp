#include "RenderTilemapSystem.h"
#include <EntityManager.hpp>
#include "../Components/Transform.h"
#include "../Components/TileMap.h"
#include <memory>

void Systems::RenderTilemapSystem::run(sf::RenderWindow & window, Assets::ResourceManager & rManager)
{
	ECS::EntityManager eManager;
	auto displayEntities = eManager.getEntitiesByComponents<Components::TileMap, Components::Transform>();

	for (auto entity : displayEntities) {
		auto tilemap = entity->getComponent<Components::TileMap>();
		auto transform = entity->getComponent<Components::Transform>();
		auto text = rManager.getAsset<sf::Texture>(tilemap->tilesetId);
		sf::Transform sfTransform;
		sfTransform.translate(transform->position.x, transform->position.y);
		sfTransform.scale(transform->scale.x, transform->scale.y);
		sfTransform.rotate(transform->rotation);
		if (text != nullptr) {
			sf::RenderStates states;
			states.texture = text.get();
			states.transform = sfTransform;
			for (const auto& kv : tilemap->layers) {
				window.draw(kv.second, states);
			}
		}
	}
}
