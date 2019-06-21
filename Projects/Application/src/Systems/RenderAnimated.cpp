#include "RenderAnimated.h"
#include <EntityManager.hpp>
#include "../Components/Transform.h"
#include "../Components/AnimatedSprite.h"


void Systems::RenderAnimated::run(float dt, Game& game)
{
	ECS::EntityManager eManager;
	auto displayEntities = eManager.getEntitiesByComponents<Components::AnimatedSprite, Components::Transform>();

	for (auto entity : displayEntities) {
		auto sprite = entity->getComponent<Components::AnimatedSprite>();
		auto transform = entity->getComponent<Components::Transform>();
		game.drawQueue.push({ (int)transform->position.z, [sprite, transform, dt](sf::RenderWindow& window, Assets::ResourceManager& rManager) {
			auto text = rManager.getAsset<sf::Texture>(sprite->id);
			if (text != nullptr) {
				sprite->sprite.setTexture(*text);
				Components::Frame current = sprite->getCurrentFrame();
				sprite->sprite.setTextureRect(sf::IntRect(current.x, current.y, current.width, current.height));
				sprite->sprite.setPosition(std::floor(transform->position.x), std::floor(transform->position.y));
				sprite->sprite.setScale(transform->scale);
				window.draw(sprite->sprite);
				sprite->update(dt);
			}
		}});		
	}
}
