#pragma once
#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "KineticBody.hpp"
#include "Input.hpp"

namespace Systems {
	static void PlayerInputSystem(float dt, sf::RenderWindow& window) {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponents<Components::Transform, Components::Input>();

		for (auto entity : entities) {
			auto transform = entity->getComponent<Components::Transform>();
			auto input = entity->getComponent<Components::Input>();

			sf::Vector3f move(0.0f, 0.0f, 0.0f);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				move += sf::Vector3f(0.0f, -input->speed, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				move += sf::Vector3f(0.0f, input->speed, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				move += sf::Vector3f(-input->speed, 0.0f, 0.0f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				move += sf::Vector3f(input->speed, 0.0f, 0.0f);
			}

			transform->position += move * dt;

			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			float angle = std::atan2(mousePosition.x - transform->position.x, mousePosition.y - transform->position.y) * Math::RADIAN_TO_DEGREES;
			transform->rotation = -angle;
		}
	}
}
