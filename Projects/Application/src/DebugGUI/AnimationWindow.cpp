#include "AnimationWindow.h"
#include "LuaConsole.h"
#include "imgui.h"
#include "imgui-SFML.h"

void Debug::AnimationWindow::Draw(Game & game) {
	ImGui::Begin("Animation Window", 0, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("Edit Animation")) {
			ImGui::EndMenu();
		}
	}
	ImGui::EndMainMenuBar();
}
