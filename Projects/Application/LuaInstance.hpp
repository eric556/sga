#pragma once
#include <sol.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

#include "Constants.hpp"


namespace Lua {
	class LuaInstance {
	public:
		static void init(){
			MainState.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os);

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
				"deleteEntity", &ECS::EntityManager::deleteEntity
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

		template<class T>
		static sol::usertype<T> registerComponent(std::string name) {
			// create the new type
			sol::usertype <T> type = MainState.new_usertype<T>(name);

			// create a method so it can be added to entities
			MainState["Entity"]["add" + name] = &ECS::Entity::addComponent<T>;
			MainState["Entity"]["remove" + name] = &ECS::Entity::removeComp<T>;
			return type;
		}


	public:
		static inline sol::state MainState;
	};
}