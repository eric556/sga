#pragma once

#include <EntityManager.hpp>
#include "Physics.hpp"


namespace Systems {
	static const inline float GRAV_CONST = 9.81f;

	static void GravitySystem() {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponent<Physics>();

		for (auto entity : physicsEntities) {
			auto physics = entity->getComponent<Physics>();
			physics->forceAccumulator += sf::Vector2f(0, GRAV_CONST);
		}
	}
}