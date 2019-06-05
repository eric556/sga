#pragma once

#include <EntityManager.hpp>
#include "Physics.hpp"
#include "Friction.hpp"

namespace Systems {
	static void FrictionSystem() {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponents<Components::Physics, Components::Friction>(Components::MOVEABLE);

		for (auto entity : entities) {
			auto physics = entity->getComponent<Components::Physics>();
			auto friction = entity->getComponent<Components::Friction>();
			sf::Vector3f velocity = physics->velocity;
			sf::Vector3f frictionDir = Math::normalize(velocity) * -1.f;
			float normalMag = Math::mag(friction->normal);
			float frictionMag = friction->frictionCoff;

			physics->forceAccumulator += (frictionDir * frictionMag);
		}
	}
}