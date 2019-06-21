#include "RenderSystem.h"
#include "../Components/Display.h"
#include "../Components/Transform.h"

namespace Systems {
	void RenderSystem::run(Game& game) {
		// ECS::EntityManager eManager;
		// 
		// auto displayEntities = eManager.getEntitiesByComponents<Components::Display, Components::Transform>();
		// 
		// for (auto entity : displayEntities) {
		// 	auto display = entity->getComponent<Components::Display>();
		// 	auto transform = entity->getComponent<Components::Transform>();
		// 	display->shape.setPosition(transform->position.x, transform->position.y);
		// 	display->shape.setScale(transform->scale);
		// 	display->shape.setRotation(transform->rotation);
		// 	window.draw(display->shape);
		// 

		while (!game.drawQueue.empty()) {
			auto drawEvent = game.drawQueue.top();
			drawEvent.drawFunction(game.window, game.rManager);
			game.drawQueue.pop();
		}
	}
}