#include "MenuBar.h"
#include "GUI.hpp"

namespace Debug {
	MenuBar::MenuBar() {
	}

	void MenuBar::Draw(Game& game) {
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("Lua")) {
				if (ImGui::MenuItem("Console", "CTRL-L")) {
					isConsoleVisible = !isConsoleVisible;
				}
				if (ImGui::MenuItem("Run Script")) {

				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Utilities")) {
				if (ImGui::MenuItem("Entity Manager")) {
					isEntityManagerVisible = !isEntityManagerVisible;
				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Game")) {
				if (ImGui::MenuItem("Pause")) {
					game.running = false;
				}

				if (ImGui::MenuItem("Run")) {
					game.running = true;
				}

				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}

		if (isConsoleVisible) {
			// TODO draw console here
			console.Draw(game);
		}

		if (isEntityManagerVisible) {
			ImGui::EntityManagerWindow("Entity Manager", game.eManager);
		}
	}
}