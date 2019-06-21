#pragma once

#include "../LuaInstance.h"
#include <EntityManager.hpp>
#include <SFML/Graphics.hpp>
#include "../Resources/ResourceManager.h"
#include <queue>
#include <functional>

struct DrawEvent {
	int zIndex;
	std::function<void(sf::RenderWindow&, Assets::ResourceManager&)> drawFunction;
	friend bool operator<(const DrawEvent& lhs, const DrawEvent& rhs) {
		return lhs.zIndex < rhs.zIndex;
	}

	friend bool operator>(const DrawEvent& lhs, const DrawEvent& rhs) {
		return lhs.zIndex > rhs.zIndex;
	}
};

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
	std::priority_queue<DrawEvent, std::vector<DrawEvent>, std::greater<DrawEvent>> drawQueue;

private:
	sol::function loadFunction;
	sol::function updateFunction;
	sol::function drawFunction;
	sf::Clock deltaClock;
};