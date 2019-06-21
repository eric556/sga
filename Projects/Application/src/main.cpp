#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>
#include <Entity.hpp>
#include <EntityManager.hpp>
#include "Engine/Game.h"

#include <string>
#include <time.h>

#include "Components/ComponentRegister.h"
#include "DebugGUI/MenuBar.h"
#include "Resources/ResourceManager.h"
#include "LuaInstance.h"
#include "Systems/GravitySystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/RenderSpriteSystem.h"
#include "Systems/PlayerInputSystem.h"
#include "Systems/RenderAnimated.h"
#include "Systems/RenderTilemapSystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/CameraSystem.h"

float random(float HI, float LO) {
	return LO + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

int main()
{
	srand(static_cast <unsigned> (time(0)));

	// Setup graphics
	Game game("SGA", 900, 900);
	game.window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(game.window);
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::GetIO().ConfigDockingWithShift = true;
	
	// Setup resources
	game.rManager.LoadTexture("dungeon_sheet", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/dungeon_sheet.png");
	game.rManager.LoadTexture("mini_char", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/mini char/spritesheet.png");
	game.rManager.LoadTexture("pokemon_sheet", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/pokemon_sheet.png");
	game.rManager.LoadTexture("pokemon_player_sheet", "C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/pokemon_player_sheet.png");


	sol::state_view view = game.lua.getStateView();

	// Setup Systems
	Systems::GravitySystem gravSys;
	Systems::PlayerInputSystem playerInputSys;
	Systems::PhysicsSystem physSys;
	Systems::RenderSystem renderSys;
	Systems::RenderSpriteSystem renderTextureSys;
	Systems::RenderAnimated renderAnimatedSys;
	Systems::RenderTilemapSystem renderTilemapSys;
	Systems::CollisionSystem colSys;
	Systems::CameraSystem camSys;

	view.set_function("drawAnimated", [&game, &renderAnimatedSys](float dt) {
		renderAnimatedSys.run(dt, game);
	});

	view.set_function("drawSprite", [&game, &renderTextureSys]() {
		renderTextureSys.run(game);
	});

	view.set_function("drawShape", [&game, &renderSys]() {
		renderSys.run(game);
	});

	view.set_function("drawTilemap", [&game, &renderTilemapSys]() {
		renderTilemapSys.run(game);
	});

	view.set_function("checkCollisions", [&game, &colSys]() {
		colSys.run(game);
	});

	view.set_function("updateCamera", [&game, &camSys]() {
		camSys.run(game);
	});

	game.Start("C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/Scripts/main.lua");
	// game.Start("C:/Users/nowace/Desktop/Projects/sga/Projects/Application/Assets/Scripts/test.lua");
	return 0;
}