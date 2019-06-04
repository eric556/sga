#pragma once

#include <EntityManager.hpp>
#include "Physics.hpp"

namespace Systems {
	static void PhysicsSystem(float dt) {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponent<Physics>();

		for (auto entity : physicsEntities) {
			auto physics = entity->getComponent<Physics>();
			physics->acceleration += physics->forceAccumulator * (1.f / physics->mass);
			physics->velocity += physics->acceleration * dt;
			physics->position += physics->velocity * dt;
			physics->forceAccumulator = sf::Vector2f(0, 0);
		}
	}
}