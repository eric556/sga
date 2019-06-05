#pragma once

#include <EntityManager.hpp>
#include "Physics.hpp"

namespace Systems {
	static void PhysicsSystem(float dt) {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponent<Components::Physics>(Components::MOVEABLE);

		for (auto entity : physicsEntities) {
			auto physics = entity->getComponent<Components::Physics>();
			physics->acceleration += physics->forceAccumulator * (1.f / physics->mass);
			physics->velocity += physics->acceleration * dt;
			physics->position += physics->velocity * dt;
			physics->forceAccumulator = sf::Vector3f(0.f, 0.f, 0.f);
		}
	}
}