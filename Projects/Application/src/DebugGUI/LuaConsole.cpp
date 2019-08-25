#include "LuaConsole.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Components/ComponentRegister.h"

#include <memory>



namespace Debug {
	LuaConsole::LuaConsole() {
		textBuffer[0] = 0;
		filePathBuffer[0] = 0;
	}

	void LuaConsole::Draw(Game& game) {
		sol::state_view stateView = game.lua.getStateView();
		ImGui::Begin("Lua Console", 0, ImGuiWindowFlags_MenuBar);
		bool fileMenuOpen = false;
		if (ImGui::BeginMenuBar()) {
			if (ImGui::BeginMenu("File")) {
				if (ImGui::MenuItem("Open Script", "CTRL-O")) {
					scriptFilePicker.isVisible = true;
					scriptFilePicker.Open("../../");
				}

				if (ImGui::MenuItem("Clear")) {
					entries.clear();
				}

				if (ImGui::MenuItem("Reset Lua State")) {
					game.lua.resetState();
				}

				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();

			scriptFilePicker.Draw(game);
			if (scriptFilePicker.fileSelected)
			{
				auto result = game.Load(scriptFilePicker.file);

				if (!result.valid()) {
					sol::error err = result;
					entries.push_back(std::string(err.what()));
				}
				else {
					entries.push_back(result);
				}
			}
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
			auto result = stateView.safe_script(textBuffer, sol::script_pass_on_error);

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


			ImGui::SetItemDefaultFocus();
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

			textBuffer[0] = 0;
		}
		ImGui::End();
	}
}