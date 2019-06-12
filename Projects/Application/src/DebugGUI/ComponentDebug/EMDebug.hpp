#pragma once
#include <EntityManager.hpp>
#include "imgui.h"
#include "imgui-SFML.h"


namespace Debug {
	class EMDebug {
	public:
		static void Draw(ECS::EntityManager eManager) {
			if (!ImGui::CollapsingHeader("Entities"))
				return;
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
	};
}
