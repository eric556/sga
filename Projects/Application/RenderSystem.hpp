#pragma once

#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "Display.hpp"
#include "Physics.hpp"

namespace Systems {
	static void RenderSystem(sf::RenderWindow& window) {
		ECS::EntityManager eManager;

		auto displayEntities = eManager.getEntitiesByComponents<Components::Display, Components::Physics>();

		for (auto entity : displayEntities) {
			auto display = entity->getComponent<Components::Display>();
			auto physics = entity->getComponent<Components::Physics>();
			display->shape.setPosition(physics->position.x, physics->position.y);
			window.draw(display->shape);
		}
	}
}
