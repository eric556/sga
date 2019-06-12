#include "RenderTextureSystem.h"
#include <EntityManager.hpp>
#include "../Components/Sprite.h"
#include "../Components/Transform.h"

namespace Systems {
	void RenderTextureSystem::run(sf::RenderWindow& window, Assets::ResourceManager& rManager) {
		ECS::EntityManager eManager;

		auto displayEntities = eManager.getEntitiesByComponents<Components::Sprite, Components::Transform>();

		for (auto entity : displayEntities) {
			auto sprite = entity->getComponent<Components::Sprite>();
			auto transform = entity->getComponent<Components::Transform>();
			auto text = rManager.getAsset<sf::Texture>(sprite->id);
			if (text != nullptr) {
				sprite->sprite.setTexture(*text);
				sprite->sprite.setPosition(transform->position.x, transform->position.y);
				sprite->sprite.setScale(transform->scale);
				window.draw(sprite->sprite);
			}
		}
	}
}