#define IMGUI_SFML
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <sol.hpp>

#include <string>
#include <time.h>

#include <Entity.hpp>
#include <EntityManager.hpp>
#include "ComponentRegistry.hpp"
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
	Lua::LuaInstance::init();
	Components::RegisterComponents();


	ECS::EntityManager eManager;
	sf::Color bgColor;

	float color[3] = { 0.f, 0.f, 0.f };
	char consoleBuffer[255] = "";

	// lua.set_function("changeBG", [&bgColor, &color](int r, int g, int b, int a) { 
	// 	bgColor = sf::Color(r, g, b, a);
	// 	color[0] = r / 255.f;
	// 	color[1] = g / 255.f;
	// 	color[2] = b / 255.f;
	// });


	Debug::MenuBar menuBar;

	// std::shared_ptr<ECS::Entity> player = eManager.createEntity();
	// std::shared_ptr<Components::KineticBody> playerPhysics = player->addComponent<Components::KineticBody>();
	// std::shared_ptr<Components::Transform> playerTransform = player->addComponent<Components::Transform>();
	// std::shared_ptr<Components::Display> playerDisplay = player->addComponent<Components::Display>();
	// playerDisplay->shape.setSize(sf::Vector2f(10.0f, 10.0f));
	// playerDisplay->shape.setOrigin(sf::Vector2f(5.f, 5.f));
	// playerTransform->position = sf::Vector3f(1920.f / 2.f, 1080.f / 2, 0.0f);
	// playerPhysics->mass = 20.0f;
	// player->name = "Player";
	// std::shared_ptr<Components::Input> playerInput = player->addComponent<Components::Input>();
	// playerInput->speed = 500.0f;
	// player->addComponent(Components::MOVEABLE);

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

		Systems::PlayerInputSystem(dt.asSeconds(), window);
		Systems::GravitySystem();
		Systems::FrictionSystem();
		Systems::PhysicsSystem(dt.asSeconds());

		window.clear(bgColor);
		Systems::RenderSystem(window);

#ifdef _DEBUG
		ImGui::SFML::Update(window, dt);
		menuBar.Draw();
		ImGui::Begin("Entity Manager");
		eManager.Debug();
		ImGui::End();
		ImGui::SFML::Render(window);
#endif // DEBUG
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}