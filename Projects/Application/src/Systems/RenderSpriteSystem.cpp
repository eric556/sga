#include "RenderSpriteSystem.h"
#include <EntityManager.hpp>
#include "../Components/Sprite.h"
#include "../Components/Transform.h"

namespace Systems {
	void RenderSpriteSystem::run(Game& game) {
		ECS::EntityManager eManager;

		auto displayEntities = eManager.getEntitiesByComponents<Components::Sprite, Components::Transform>();

		for (auto entity : displayEntities) {
			auto sprite = entity->getComponent<Components::Sprite>();
			auto transform = entity->getComponent<Components::Transform>();
			Components::Transform relTransform = transform->getRelativeTo(entity);

			game.drawQueue.push({ (int)relTransform.position.z, [sprite, relTransform](sf::RenderWindow& window, Assets::ResourceManager& rManager) {
				auto text = rManager.getAsset<sf::Texture>(sprite->id);
				if (text != nullptr) {
					if (sprite->useTextureRect) {
						sprite->sprite.setTextureRect(sprite->textureRect);
					} else {
					  sprite->sprite.setTextureRect(sf::IntRect(0, 0, text->getSize().x, text->getSize().y));
					}

					sprite->sprite.setTexture(*text);
					sprite->sprite.setPosition(std::floor(relTransform.position.x), std::floor(relTransform.position.y));
					sprite->sprite.setScale(relTransform.scale);
					window.draw(sprite->sprite);
				}
			}});

			
		}
	}
}