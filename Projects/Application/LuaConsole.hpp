#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <sol.hpp>


#include <vector>
#include <string>
#include <memory>

class LuaConsole {
public:
	LuaConsole() : lua(nullptr) {
		textBuffer[0] = 0;
		visible = false;
	}

	void init(sol::state* luaState) {
		lua = luaState;
	}

	~LuaConsole() {}

	void Draw() {
		if (!visible) return;
		ImGui::Begin("Lua Console", 0, ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar()) {
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open Script", "CTRL-O")) {
					// todo load file here
				}

				if (ImGui::MenuItem("Clear")) {
					entries.clear();
				}

				if (ImGui::MenuItem("Close")) {
					visible = false;
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		
		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
		ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve));
		for (std::string& text : entries) {
			if (text != "") {
				ImGui::Text(("> " + text).c_str());
			}
		}
		ImGui::SetScrollHereY(1.0f);
		ImGui::EndChild();
		ImGui::Separator();


		if (ImGui::InputTextMultiline("", textBuffer, 255, ImVec2(-1.0f, ImGui::GetTextLineHeight() + 15), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CtrlEnterForNewLine | ImGuiInputTextFlags_AllowTabInput)) {
			if (lua != nullptr) {
				auto result = lua->safe_script(textBuffer, sol::script_pass_on_error);

				if (!result.valid()) {
					sol::error err = result;
					entries.push_back(std::string(textBuffer));
					entries.push_back("! Error running command");
					entries.push_back("!\t" + std::string(err.what()));
				}
				else {
					entries.push_back(textBuffer);
					entries.push_back(result);
				}


			} else {
				entries.push_back("Lua has not been initialized");
			}

			ImGui::SetItemDefaultFocus();
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

			textBuffer[0] = 0;
		}
		ImGui::End();
	}

	bool visible;
private:
	char textBuffer[255];
	std::vector<std::string> entries;
	sol::state* lua;
};