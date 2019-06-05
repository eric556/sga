#pragma once
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include "Physics.hpp"
#include "Drag.hpp"

#include "Helpers.hpp"

static inline const float AIR_DENSITY = 1.f; // kg/m^3 

namespace Systems {
	static void DragSystem() {
		ECS::EntityManager eManager;
		auto entities = eManager.getEntitiesByComponents<Components::Physics, Components::Drag>(Components::MOVEABLE);

		for (auto entity : entities) {
			auto physics = entity->getComponent<Components::Physics>();
			auto drag = entity->getComponent<Components::Drag>();

			float speed = Math::mag(physics->velocity);
			sf::Vector3f dragDir = physics->velocity /= ((speed == 0.0f)? 1.0f: speed);
			dragDir *= -1.0f;

			float dragMag = drag->dragCoff * speed * speed;


			physics->forceAccumulator += (dragDir * dragMag);
			entity->removeComp<Components::Drag>();
		}
	}
}
