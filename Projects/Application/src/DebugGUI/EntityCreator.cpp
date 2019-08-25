#include "EntityCreator.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "GUI.h"

void Debug::EntityCreator::Draw(Game & game)
{
	ImGui::Begin("Entity Creator", 0, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("New Entity")) {
				currentEntity = game.eManager.createEntity();
			}

			if (ImGui::MenuItem("Edit Entity")) {

			}

			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	if (auto spt = currentEntity.lock()) {
		std::string header = spt->name + " " + std::to_string(spt->id);
		ImGui::EntityNode(header, spt);
		ImGui::Text(header.c_str());
	}

	ImGui::End();
}
