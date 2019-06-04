#define IMGUI_SFML
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>

#include <string>
#include <time.h>

#include <Entity.hpp>
#include <EntityManager.hpp>
#include "Display.hpp"
#include "MenuBar.hpp"


float random(float HI, float LO) {
	return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

int main()
{
	srand(static_cast <unsigned> (time(0)));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SGA");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);


	EntityManager eManager;
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os);
	sf::Color bgColor;

	lua.new_usertype<EntityManager>("em",
		"entities", sol::var(std::ref(EntityManager::entities)),
		"entityCount", sol::var(std::ref(EntityManager::entityCount)),
		"createEntity", &EntityManager::createEntity
	);


	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";

	lua.set_function("changeBG", [&bgColor, &color](int r, int g, int b, int a) { 
		bgColor = sf::Color(r, g, b, a);
		color[0] = r / 255.f;
		color[1] = g / 255.f;
		color[2] = b / 255.f;
	});


	MenuBar menuBar;
	menuBar.init(&lua);

	for (int i = 0; i < 100; i++) {
		std::shared_ptr<Entity> entity = eManager.createEntity();
		std::shared_ptr<Display> display = entity->addComponent<Display>();
		display->shape.setPosition(sf::Vector2f(random(0, 1280), random(0, 720)));
		display->shape.setSize(sf::Vector2f(10, 10));
		display->shape.setFillColor(sf::Color::Red);
	}

	window.resetGLStates();
	sf::Clock deltaClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

#ifdef _DEBUG

		ImGui::SFML::Update(window, deltaClock.restart());

		menuBar.Draw();

		ImGui::Begin("Sample Window");

		if (ImGui::ColorEdit3("Background color", color)) {
			bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
			bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
			bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		}

		eManager.Debug();
		
		ImGui::End();

#endif // DEBUG

		window.clear(bgColor);

		auto displayEntities = eManager.getEntitiesByComponent<Display>();

		for (auto entity : displayEntities) {
			auto display = entity->getComponent<Display>();
			window.draw(display->shape);
		}

#ifdef _DEBUG
		ImGui::SFML::Render(window);
#endif // DEBUG
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}