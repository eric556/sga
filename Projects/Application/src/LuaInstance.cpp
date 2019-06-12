#include "LuaInstance.h"

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include "Constants.hpp"


namespace Lua {
	LuaInstance::LuaInstance() {
		MainState.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os, sol::lib::math);

		MainState.new_usertype<sf::Vector2f>("Vector2",
			sol::constructors <sf::Vector2f(float, float)>(),
			"x", &sf::Vector2f::x,
			"y", &sf::Vector2f::y
			);


		MainState.new_usertype<sf::Vector3f>("Vector3",
			sol::constructors <sf::Vector3f(float, float, float)>(),
			"x", &sf::Vector3f::x,
			"y", &sf::Vector3f::y,
			"z", &sf::Vector3f::z
			);


		MainState.new_usertype<sf::Color>("Color",
			sol::constructors < sf::Color(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)>(),
			"r", &sf::Color::r,
			"g", &sf::Color::g,
			"b", &sf::Color::b,
			"a", &sf::Color::a
			);


		MainState.new_usertype<sf::RectangleShape>("RectangleShape",
			sol::constructors<sf::RectangleShape(const sf::Vector2f& size)>(),
			"setSize", &sf::RectangleShape::setSize,
			"setColor", &sf::RectangleShape::setFillColor,
			"setOrigin", sol::resolve<void(float, float)>(&sf::RectangleShape::setOrigin)
			);


		MainState.new_enum("Tags",
			"GRAVITY", Components::ComponentType::GRAVITY,
			"MOVEABLE", Components::ComponentType::MOVEABLE
		);

		MainState.new_usertype<ECS::EntityManager>("EntityManager",
			"entities", sol::var(std::ref(ECS::EntityManager::entities)),
			"entityCount", sol::var(std::ref(ECS::EntityManager::entityCount)),
			"createEntity", &ECS::EntityManager::createEntity,
			"deleteEntity", &ECS::EntityManager::deleteEntity,
			"getEntity", &ECS::EntityManager::getEntityByID
			);

		MainState["entityManager"] = ECS::EntityManager();

		MainState.new_usertype<ECS::Entity>("Entity",
			sol::constructors<ECS::Entity(unsigned int)>(),
			"id", &ECS::Entity::id,
			"name", &ECS::Entity::name,
			"addTag", &ECS::Entity::addComponent,
			"removeTag", &ECS::Entity::removeComp
			);
	}

	sol::state_view LuaInstance::getStateView() {
		return sol::state_view(MainState);
	}
}