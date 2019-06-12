#include "PhysicsSystem.h"
#include <EntityManager.hpp>
#include "../Components/KineticBody.h"
#include "../Components/Transform.h"
#include "../Constants.hpp"

namespace Systems {
	void PhysicsSystem::run(float dt) {
		ECS::EntityManager eManager;
		auto physicsEntities = eManager.getEntitiesByComponents<Components::KineticBody, Components::Transform>(Components::MOVEABLE);

		for (auto entity : physicsEntities) {
			auto kb = entity->getComponent<Components::KineticBody>();
			auto transform = entity->getComponent<Components::Transform>();
			kb->acceleration += kb->forceAccumulator * (1.f / kb->mass);
			kb->velocity += kb->acceleration * dt;
			transform->position += kb->velocity * dt;
			kb->forceAccumulator = sf::Vector3f(0.f, 0.f, 0.f);
		}
	}
}