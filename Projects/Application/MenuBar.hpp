#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include "LuaConsole.hpp"

#include <vector>
#include <string>
#include <memory>

namespace Debug {
	class MenuBar {
	public:
		MenuBar() {
			visible = true;
		}

		void Draw() {
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

		bool visible;
	private:
		LuaConsole console;

	};
}