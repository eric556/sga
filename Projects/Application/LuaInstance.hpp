#pragma once
#include <sol.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>


namespace Lua {
	static class LuaInstance {
	public:
		static void init(){
			MainState.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os);

			MainState.new_usertype<sf::Vector2f>("Vector2f",
				sol::constructors <sf::Vector2f(float, float)>(),
				"x", &sf::Vector2f::x,
				"y", &sf::Vector2f::y
			);

			MainState.new_usertype<sf::Vector3f>("Vector3f",
				sol::constructors <sf::Vector3f(float, float, float)>(),
				"x", &sf::Vector3f::x,
				"y", &sf::Vector3f::y,
				"z", &sf::Vector3f::z
			);

			MainState.new_usertype<ECS::EntityManager>("EntityManager",
				"entities", sol::var(std::ref(ECS::EntityManager::entities)),
				"entityCount", sol::var(std::ref(ECS::EntityManager::entityCount)),
				"createEntity", &ECS::EntityManager::createEntity
			);

			MainState.new_usertype<ECS::Entity>("Entity",
				sol::constructors<ECS::Entity(unsigned int)>(),
				"id", &ECS::Entity::id,
				"name", &ECS::Entity::name,
				"addTag", &ECS::Entity::addComponent,
				"removeTag", &ECS::Entity::removeComp
			);
		}

		template<class T>
		static void registerComponent(std::string name) {
			// create the new type
			sol::usertype <T> type = MainState.new_usertype<T>(name);

			// create a method so it can be added to entities
			MainState["Entity"]["add" + name] = &ECS::Entity::addComponent<T>;
			MainState["Entity"]["remove" + name] = &ECS::Entity::removeComp<T>;
		}


	public:
		static inline sol::state MainState;
	};
}