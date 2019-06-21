#include "LuaInstance.h"

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include "Constants.hpp"
#include "Helpers.hpp"


namespace Lua {

	void LuaInstance::Init() {
		MainState.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os, sol::lib::math);
		const std::string package_path = MainState["package"]["path"];
		MainState["package"]["path"] = package_path + ((!package_path.empty()) ? ";" : "") + "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/Scripts/?.lua;C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/Scripts/?/?.lua";

		MainState.new_usertype<sf::Vector2f>("Vector2",
			sol::constructors <sf::Vector2f(float, float)>(),
			"x", &sf::Vector2f::x,
			"y", &sf::Vector2f::y
			);

		MainState.new_usertype<sf::Vector3f>("Vector3",
			sol::constructors <sf::Vector3f(float, float, float)>(),
			"x", &sf::Vector3f::x,
			"y", &sf::Vector3f::y,
			"z", &sf::Vector3f::z,
			sol::meta_function::addition, sol::resolve<sf::Vector3f(const sf::Vector3f&, const sf::Vector3f&)>(sf::operator+),
			sol::meta_function::subtraction, sol::resolve<sf::Vector3f(const sf::Vector3f&, const sf::Vector3f&)>(sf::operator-),
			sol::meta_function::multiplication, sol::resolve<sf::Vector3f(const sf::Vector3f&, float)>(sf::operator*)
			);

		MainState.new_usertype<sf::IntRect>("IntRect",
			sol::constructors<sf::IntRect(int, int, int, int)>(),
			"top", &sf::IntRect::top,
			"left", &sf::IntRect::left,
			"width", &sf::IntRect::width,
			"height", &sf::IntRect::height			
			);

		MainState.new_usertype<sf::FloatRect>("FloatRect",
			sol::constructors<sf::FloatRect(float, float, float, float)>(),
			"top", &sf::FloatRect::top,
			"left", &sf::FloatRect::left,
			"width", &sf::FloatRect::width,
			"height", &sf::FloatRect::height
			);

		MainState.set_function("Normalize", &Math::normalize);

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

		MainState.new_usertype<sf::Sprite>("Sprite",
			"setOrigin", sol::resolve<void(float, float)>(&sf::Sprite::setOrigin)
			);

		MainState.new_enum("Tags",
			"GRAVITY", Components::ComponentType::GRAVITY,
			"MOVEABLE", Components::ComponentType::MOVEABLE
		);


		MainState.new_usertype<ECS::EntityManager>("EntityManager",
			"entities", sol::var(std::ref(ECS::EntityManager::entities)),
			"entityCount", sol::var(std::ref(ECS::EntityManager::entityCount)),
			"createEntity", sol::resolve<std::shared_ptr<ECS::Entity>()>(&ECS::EntityManager::createEntity),
			"createEntityOnParent", sol::resolve<std::shared_ptr<ECS::Entity>(std::shared_ptr<ECS::Entity>&)>(&ECS::EntityManager::createEntity),
			"deleteEntity", &ECS::EntityManager::deleteEntity,
			"getEntity", &ECS::EntityManager::getEntityByID
			);

		MainState["entityManager"] = ECS::EntityManager();

		MainState.new_usertype<ECS::Entity>("Entity",
			sol::constructors<ECS::Entity(unsigned int)>(),
			"id", &ECS::Entity::id,
			"name", &ECS::Entity::name,
			"addTag", &ECS::Entity::addComponent,
			"removeTag", &ECS::Entity::removeComp,
			"addChild", &ECS::Entity::addChild,
			"removeChild", &ECS::Entity::removeChild,
			"dump", [](ECS::Entity& self) {
					for (auto& comp : self.components) {
						std::cout << comp->dump(self.name) << std::endl;
					}
				}
			);

		MainState.create_named_table("Systems");

		MainState.set_function("getKeyDown", [](unsigned int key) -> bool {
			return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
		});
	}

	sol::state_view LuaInstance::getStateView() {
		return sol::state_view(MainState);
	}

	void LuaInstance::resetState() {
		MainState = sol::state();
	}
}