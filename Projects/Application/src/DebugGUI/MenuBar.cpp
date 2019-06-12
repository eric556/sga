#include "MenuBar.h"

namespace Debug {
	MenuBar::MenuBar(Lua::LuaInstance& instance) : console(instance), stateView(instance.getStateView()) {
		visible = true;
	}

	void MenuBar::Draw() {
		if (!visible) return;
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

		console.Draw();
	}
}