#define IMGUI_SFML
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>

#include <string>
#include <time.h>

#include <Entity.hpp>
#include <EntityManager.hpp>
#include "Components.h"
#include "Systems.h"
#include "MenuBar.hpp"


float random(float HI, float LO) {
	return LO + static_cast <float> (std::rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

int main()
{
	srand(static_cast <unsigned> (time(0)));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SGA");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);


	ECS::EntityManager eManager;
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::os);
	sf::Color bgColor;

	lua.new_usertype<ECS::EntityManager>("em",
		"entities", sol::var(std::ref(ECS::EntityManager::entities)),
		"entityCount", sol::var(std::ref(ECS::EntityManager::entityCount)),
		"createEntity", &ECS::EntityManager::createEntity
	);


	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";

	lua.set_function("changeBG", [&bgColor, &color](int r, int g, int b, int a) { 
		bgColor = sf::Color(r, g, b, a);
		color[0] = r / 255.f;
		color[1] = g / 255.f;
		color[2] = b / 255.f;
	});


	Debug::MenuBar menuBar;
	menuBar.init(&lua);

	for (int i = 0; i < 100; i++) {
		std::shared_ptr<ECS::Entity> entity = eManager.createEntity();
		std::shared_ptr<Components::Display> display = entity->addComponent<Components::Display>();
		display->shape.setSize(sf::Vector2f(10, 10));
		display->shape.setFillColor(sf::Color::Red);
	
		std::shared_ptr<Components::Physics> physics = entity->addComponent<Components::Physics>();
		physics->position = sf::Vector3f(random(0, 1280), random(0, 720), 0.0f );
		physics->mass = random(1, 100);
		physics->surfaceArea = 0.01f;
	
		entity->addComponent(Components::GRAVITY);
		entity->addComponent(Components::MOVEABLE);
	}

	std::shared_ptr<ECS::Entity> player = eManager.createEntity();
	std::shared_ptr<Components::Physics> playerPhysics = player->addComponent<Components::Physics>();
	std::shared_ptr<Components::Display> playerDisplay = player->addComponent<Components::Display>();
	player->name = "Player";
	player->addComponent(Components::INPUT);

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

		Systems::PlayerInputSystem();

		Systems::DragSystem();
		Systems::GravitySystem();
		Systems::PhysicsSystem(dt.asSeconds());

		window.clear(bgColor);
		Systems::RenderSystem(window);

#ifdef _DEBUG
		ImGui::SFML::Update(window, dt);
		menuBar.Draw();
		ImGui::Begin("Sample Window");
		eManager.Debug();
		ImGui::End();
		ImGui::SFML::Render(window);
#endif // DEBUG
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}