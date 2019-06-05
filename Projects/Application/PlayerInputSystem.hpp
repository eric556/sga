#pragma once
#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "Physics.hpp"

namespace Systems {
	static void PlayerInputSystem() {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponent<Components::Physics>(Components::INPUT);

		for (auto entity : entities) {
			auto physics = entity->getComponent<Components::Physics>();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				physics->velocity = sf::Vector3f(0, -100.f, 0.0f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				physics->velocity = sf::Vector3f(0, 100.f, 0.0f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				physics->velocity = sf::Vector3f(-100.0f, 0.0f, 0.0f);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				physics->velocity = sf::Vector3f(100.0f, 0.0f, 0.0f);
			}
			else {
			}
		}
	}
}
