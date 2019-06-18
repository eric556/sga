#pragma once
#include "../LuaInstance.h"
#include "../Engine/Game.h"
#include "LuaConsole.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <EntityManager.hpp>

namespace ImGui {
	void EntityManagerWindow(std::string name, ECS::EntityManager& eManager) {
		Begin(name.c_str());
		if (ImGui::CollapsingHeader("Entities")){
			for (auto entity : eManager.entities) {
				std::string entityHeader = "";
					if (entity->name == "") {
						entityHeader = "Entity " + std::to_string(entity->id);

					}
					else {
						entityHeader = entity->name;
					}
				if (ImGui::TreeNode(entityHeader.c_str())) {
					if (ImGui::TreeNode("Components")) {
						for (auto component : entity->components) {
							if (ImGui::TreeNode(component->name.c_str())) {
								component->debug();
								ImGui::TreePop();
							}
						}
						ImGui::TreePop();
					}

					ImGui::TreePop();
				}
			}
		}
		End();
	}
}