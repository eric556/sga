#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>

#include <string>

#include <Entity.hpp>
#include <EntityManager.hpp>
#include "Display.hpp"
#include "LuaConsole.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SGA");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);


	EntityManager eManager;
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os);
	sf::Color bgColor;


	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";

	lua.set_function("changeBG", [&bgColor, &color](int r, int g, int b, int a) { 
		bgColor = sf::Color(r, g, b, a);
		color[0] = r / 255.f;
		color[1] = g / 255.f;
		color[2] = b / 255.f;
	});

	std::vector<std::string> texts;

	Entity entity;
	entity.addComponent<Display>()->shape.setOutlineColor(sf::Color::Red);

	LuaConsole console(&lua);

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

		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("Lua")) {
				if (ImGui::MenuItem("Console", "CTRL-L")) {
					console.visible = true;
				}
				if (ImGui::MenuItem("Run Script")) {}

				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

		ImGui::Begin("Sample Window");

		if (ImGui::ColorEdit3("Background color", color)) {
			bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
			bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
			bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		}

		entity.getComponent<Display>()->debug();
		
		ImGui::End();

		console.Draw();

#endif // DEBUG

		window.clear(bgColor);
#ifdef _DEBUG
		ImGui::SFML::Render(window);
#endif // DEBUG
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}