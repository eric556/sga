#include "CollisionSystem.h"
#include <EntityManager.hpp>
#include "../Components/Transform.h"
#include "../Components/BoundingBox.h"
#include <SFML/Graphics.hpp>

void Systems::CollisionSystem::run(Game & game)
{
	ECS::EntityManager eManager;
	auto entities = eManager.getEntitiesByComponents < Components::BoundingBox, Components::Transform > ();

	for (auto entity : entities) {
		auto boundingBox = entity->getComponent<Components::BoundingBox>();
		auto transform = entity->getComponent<Components::Transform>();
		if (boundingBox->display) {

			game.drawQueue.push({ 1000,[transform, boundingBox](sf::RenderWindow& window, Assets::ResourceManager& rManager) {
				sf::RectangleShape shape;
				shape.setPosition(transform->position.x + boundingBox->boundingBox.left, transform->position.y + boundingBox->boundingBox.top);
				shape.setSize(sf::Vector2f(boundingBox->boundingBox.width, boundingBox->boundingBox.height));
				shape.setOutlineColor(sf::Color::Red);
				shape.setOutlineThickness(2.0f);
				shape.setFillColor(sf::Color::Transparent);

				window.draw(shape);
			} });
		}
	}
}
