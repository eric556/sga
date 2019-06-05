#pragma once

#include <EntityManager.hpp>
#include "Physics.hpp"


namespace Systems {
	static const inline float GRAV_CONST = 9.81f;

	static void GravitySystem() {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponent<Components::Physics>(Components::GRAVITY);

		for (auto entity : physicsEntities) {
			auto physics = entity->getComponent<Components::Physics>();
			// physics->forceAccumulator += sf::Vector3f(0.f, GRAV_CONST, 0.f);
			physics->forceAccumulator += sf::Vector3f(0.0f, GRAV_CONST * physics->mass, 0.0f);
		}
	}
}