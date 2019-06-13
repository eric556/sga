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
#include "Systems/RenderAnimated.h"


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

	sol::state_view view = luaInstance.getStateView();

	// Setup ECS
	ECS::EntityManager eManager;
	Systems::GravitySystem gravSys;
	Systems::PlayerInputSystem playerInputSys;
	Systems::PhysicsSystem physSys;
	Systems::RenderSystem renderSys;
	Systems::RenderTextureSystem renderTextureSys;
	Systems::RenderAnimated renderAnimatedSys;

	// Setup game methods
	view.safe_script_file("C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/Scripts/display-test.lua");
	sol::function loadFunction = view["load"];
	sol::function updateFunction = view["update"];
	sol::function drawFunction = view["draw"];

	view.set_function("drawAnimated", [&window, &rManager, &renderAnimatedSys](float dt) {
		renderAnimatedSys.run(dt, window, rManager);
	});

	view.set_function("drawTexture", [&window, &rManager, &renderTextureSys]() {
		renderTextureSys.run(window, rManager);
	});

	view.set_function("drawShape", [&window, &renderSys]() {
		renderSys.run(window);
	});

	view.set_function("getKeyDown", [&window](unsigned int key) -> bool {
		return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
	});

	sf::Color bgColor;

	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";

	if (loadFunction.valid()) {
		loadFunction();
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

		sf::Time dt = deltaClock.restart();

		// playerInputSys.run(dt.asSeconds(), window);
		gravSys.run();
		physSys.run(dt.asSeconds());

		if (updateFunction.valid()) {
			updateFunction(dt.asSeconds());
		}

		window.clear(bgColor);

		if (drawFunction.valid()) {
			drawFunction(dt.asSeconds());
		}

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