#include "CameraSystem.h"
#include <EntityManager.hpp>
#include "../Components/Camera.h"
#include "../Components/Transform.h"

void Systems::CameraSystem::run(Game & game)
{
	ECS::EntityManager eManager;
	auto entities = eManager.getEntitiesByComponents < Components::Camera>();
	for (auto entity : entities) {
		auto camera = entity->getComponent<Components::Camera>();
		if (auto spt = camera->followEntity.lock()) {
			auto transform = spt->getComponent<Components::Transform>();
			camera->view.setCenter(std::floor(transform->position.x), std::floor(transform->position.y));
			game.window.setView(camera->view);
		}
	}
}
