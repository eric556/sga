#include "PlayerInputSystem.h"
#include <EntityManager.hpp>
#include "../Components/KineticBody.h"
#include "../Components/Transform.h"
#include "../Components/Input.h"
#include "../Components/AnimatedSprite.h"
#include "../Constants.hpp"
#include "../Helpers.hpp"


namespace Systems {
	void PlayerInputSystem::run(float dt, sf::RenderWindow& window) {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponents<Components::Transform, Components::Input, Components::AnimatedSprite>();

		for (auto entity : entities) {
			auto transform = entity->getComponent<Components::Transform>();
			auto input = entity->getComponent<Components::Input>();
			auto sprite = entity->getComponent<Components::AnimatedSprite>();

			sf::Vector3f move(0.0f, 0.0f, 0.0f);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				move += sf::Vector3f(0.0f, -1.0, 0.0f);
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				move += sf::Vector3f(0.0f, 1.0, 0.0f);
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				move += sf::Vector3f(-1.0, 0.0f, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				move += sf::Vector3f(1.0, 0.0f, 0.0f);
			}

			if (move.x > 0 && move.y == 0) {
				sprite->setCurrentAnimation("right");
			} else if (move.x < 0 && move.y == 0) {
				sprite->setCurrentAnimation("left");
			} else if (move.x == 0 && move.y < 0) {
				sprite->setCurrentAnimation("up");
			} else if (move.x == 0 && move.y > 0) {
				sprite->setCurrentAnimation("down");
			} else if (move.x > 0 && move.y > 0) {
				sprite->setCurrentAnimation("down_right");
			} else if (move.x > 0 && move.y < 0) {
				sprite->setCurrentAnimation("up_right");
			} else if (move.x < 0 && move.y > 0) {
				sprite->setCurrentAnimation("down_left");
			} else if (move.x < 0 && move.y < 0) {
				sprite->setCurrentAnimation("up_left");
			} else {
				sprite->setCurrentAnimation("idle");
			}



			transform->position += Math::normalize(move) * input->speed * dt;

			// sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			// float angle = std::atan2(mousePosition.x - transform->position.x, mousePosition.y - transform->position.y) * Math::RADIAN_TO_DEGREES;
			// transform->rotation = -angle;
		}
	}
}