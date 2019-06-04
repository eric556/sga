#pragma once
#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "Physics.hpp"

namespace Systems {
	static void PlayerInputSystem() {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponent<Physics>(CompConsts::INPUT);

		for (auto entity : entities) {
			auto physics = entity->getComponent<Physics>();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				physics->velocity = sf::Vector2f(0, -10.f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				physics->velocity = sf::Vector2f(0, 10.f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				physics->velocity = sf::Vector2f(-10.0f, 0.0f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				physics->velocity = sf::Vector2f(10.0f, 0.0f);
			}
			else {
				physics->velocity = sf::Vector2f(0.0f, 0.0f);
			}
		}
	}
}
