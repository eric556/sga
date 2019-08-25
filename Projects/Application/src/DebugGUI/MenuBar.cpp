#include "MenuBar.h"
#include "GUI.h"
#include "imgui.h"
#include "imgui-SFML.h"

namespace Debug {
	MenuBar::MenuBar() {
	}

	void MenuBar::Draw(Game& game) {
		if (ImGui::BeginMainMenuBar()) {
			if (ImGui::BeginMenu("Lua")) {
				if (ImGui::MenuItem("Console", "CTRL-L")) {
					console.isVisible = !console.isVisible;
				}
				if (ImGui::MenuItem("Run Script")) {

				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Utilities")) {
				if (ImGui::MenuItem("Entity Manager")) {
					isEntityManagerVisible = !isEntityManagerVisible;
				}

				if (ImGui::MenuItem("Entity Creator")) {
					entityCreator.isVisible = !entityCreator.isVisible;
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

		if (console.isVisible) {
			console.Draw(game);
		}

		if (entityCreator.isVisible) {
			entityCreator.Draw(game);
		}

		if (isEntityManagerVisible) {
			ImGui::EntityManagerWindow("Entity Manager", game.eManager);
		}
	}
}