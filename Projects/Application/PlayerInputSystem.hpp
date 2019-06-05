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

			sf::Vector3f force(0.0f, 0.0f, 0.0f);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				force += sf::Vector3f(0.0f, -100.0f, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				force += sf::Vector3f(0.0f, 100.0f, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				force += sf::Vector3f(-100.0f, 0.0f, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				force += sf::Vector3f(100.0f, 0.0f, 0.0f);
			}

			physics->forceAccumulator += force;
		}
	}
}
