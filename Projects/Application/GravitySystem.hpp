#pragma once

#include <EntityManager.hpp>
#include "KineticBody.hpp"


namespace Systems {
	static const inline float GRAV_CONST = 9.81f;

	static void GravitySystem() {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponent<Components::KineticBody>(Components::GRAVITY);

		for (auto entity : physicsEntities) {
			auto kb = entity->getComponent<Components::KineticBody>();
			kb->forceAccumulator += sf::Vector3f(0.0f, GRAV_CONST * kb->mass, 0.0f);
		}
	}
}