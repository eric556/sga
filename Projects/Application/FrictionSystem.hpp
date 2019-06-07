#pragma once

#include <EntityManager.hpp>
#include "KineticBody.hpp"
#include "Friction.hpp"

namespace Systems {
	static void FrictionSystem() {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponents<Components::KineticBody, Components::Friction>(Components::MOVEABLE);

		for (auto entity : entities) {
			auto kb = entity->getComponent<Components::KineticBody>();
			auto friction = entity->getComponent<Components::Friction>();
			sf::Vector3f velocity = kb->velocity;
			sf::Vector3f frictionDir = Math::normalize(velocity) * -1.f;
			float normalMag = Math::mag(friction->normal);
			float frictionMag = friction->frictionCoff;

			kb->forceAccumulator += (frictionDir * frictionMag);
		}
	}
}