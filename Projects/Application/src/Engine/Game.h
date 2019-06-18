#pragma once

#include "../LuaInstance.h"
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include "../Resources/ResourceManager.h"

class Game {
public:
	Game(std::string name, unsigned int width, unsigned int height);
	void Start();
	void Start(std::string filepath);
	sol::function_result Load(std::string filepath);

public:
	Lua::LuaInstance lua;
	ECS::EntityManager eManager;
	sf::RenderWindow window;
	Assets::ResourceManager rManager;
	bool running;

private:
	sol::function loadFunction;
	sol::function updateFunction;
	sol::function drawFunction;
	sf::Clock deltaClock;
};