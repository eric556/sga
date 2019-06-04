#pragma once

#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "Display.hpp"
#include "Physics.hpp"

namespace Systems {
	static void RenderSystem(sf::RenderWindow& window) {
		ECS::EntityManager eManager;

		auto displayEntities = eManager.getEntitiesByComponents<Display, Physics>();

		for (auto entity : displayEntities) {
			auto display = entity->getComponent<Display>();
			auto physics = entity->getComponent<Physics>();
			display->shape.setPosition(physics->position.x, physics->position.y);
			window.draw(display->shape);
		}
	}
}
