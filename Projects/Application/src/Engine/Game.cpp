#include "Game.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Components/ComponentRegister.h"
#include "../DebugGUI/MenuBar.h"




Game::Game(std::string name, unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), name) {
	lua.Init();
	Components::ComponenetRegister::RegisterComponents(lua);
	running = true;
}

void Game::Start() {
#ifdef _DEBUG
	Debug::MenuBar menuBar;
#endif // _DEBUG

	sol::state_view view = lua.getStateView();

	window.resetGLStates();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		sf::Time dt = deltaClock.restart();

		if (running) {
			view.script("update(" + std::to_string(dt.asSeconds()) + ")");
		}


		window.clear(sf::Color::Black);

		view.script("draw(" + std::to_string(dt.asSeconds()) + ")");


#ifdef _DEBUG
		ImGui::SFML::Update(window, dt);
		// ImGui::ShowDemoWindow();


		menuBar.Draw(*this);
		ImGui::SFML::Render(window);
#endif // _DEBUG

		window.display();
	}

	ImGui::SFML::Shutdown();
}

void Game::Start(std::string filepath) {
	Load(filepath);
	this->Start();
}

sol::function_result Game::Load(std::string filepath) {
	sol::state_view view = lua.getStateView();
	auto result = view.safe_script_file(filepath, sol::script_throw_on_error, sol::load_mode::text);

	view.script("load()");

	return result;
}