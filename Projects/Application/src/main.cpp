#define IMGUI_SFML
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>

#include <string>
#include <time.h>

#include "Components/ComponentRegister.h"
#include "DebugGUI/MenuBar.h"
#include "DebugGUI/ComponentDebug/EMDebug.hpp"
#include "Resources/ResourceManager.h"
#include "LuaInstance.h"
#include "Systems/GravitySystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/RenderTextureSystem.h"
#include "Systems/PlayerInputSystem.h"


float random(float HI, float LO) {
	return LO + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

int main()
{
	srand(static_cast <unsigned> (time(0)));

	// Setup graphics
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SGA");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);

	// Setup lua stuff
	Lua::LuaInstance luaInstance;
	Components::ComponenetRegister::RegisterComponents(luaInstance);
	Debug::MenuBar menuBar(luaInstance);

	// Setup resources
	Assets::ResourceManager rManager;
	rManager.LoadTexture("dungeon_sheet", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/dungeon_sheet.png");
	rManager.LoadTexture("mini_char", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/mini char/spritesheet.png");

	// Setup ECS
	ECS::EntityManager eManager;
	Systems::GravitySystem gravSys;
	Systems::PlayerInputSystem playerInputSys;
	Systems::PhysicsSystem physSys;
	Systems::RenderSystem renderSys;
	Systems::RenderTextureSystem renderTextureSys;


	sf::Color bgColor;

	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";


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

		sf::Time dt = deltaClock.restart();

		playerInputSys.run(dt.asSeconds(), window);
		gravSys.run();
		physSys.run(dt.asSeconds());

		window.clear(bgColor);
		renderSys.run(window);
		renderTextureSys.run(window, rManager);

#ifdef _DEBUG
		ImGui::SFML::Update(window, dt);
		menuBar.Draw();
		ImGui::Begin("Entity Manager");
		// eManager.Debug();
		Debug::EMDebug::Draw(eManager);
		ImGui::End();
		ImGui::SFML::Render(window);
#endif // DEBUG
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}