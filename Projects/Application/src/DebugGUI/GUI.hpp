#pragma once
#include "../LuaInstance.h"
#include "../Engine/Game.h"
#include "LuaConsole.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <EntityManager.hpp>

namespace ImGui {
	std::string CreateEntityHeaderString(std::shared_ptr<ECS::Entity> entity) {
		std::string entityHeader = "";
		if (entity->name == "") {
			entityHeader = "Entity " + std::to_string(entity->id);

		}
		else {
			entityHeader = entity->name;
		}

		return entityHeader;
	}

	bool EntityNode(std::string name, std::shared_ptr<ECS::Entity> entity) {
		if (ImGui::TreeNode(name.c_str())) {
			if (ImGui::TreeNode("Components")) {
				for (auto component : entity->components) {
					if (ImGui::TreeNode(component->name.c_str())) {
						component->debug();
						ImGui::TreePop();
					}
				}
				ImGui::TreePop();
			}

			if (!entity->children.empty()) {
				if (ImGui::TreeNode("Children")) {
					for (auto child : entity->children) {
						if (auto spt = child.lock()) {
							if (EntityNode(CreateEntityHeaderString(spt), spt)) {
								// idk
							}
						}
					}
					ImGui::TreePop();
				}
			}

			if (ImGui::Button("Dump", sf::Vector2f(60.0f, 25.f))) {
				if (auto spt = entity->parent.lock()) {
					std::cout << "local " << entity->name << " = entityManager:createEntityOnParent(" << spt->name << ")" << std::endl;
					std::cout << entity->name << ".name = '" << entity->name << "'" << std::endl;
				} else {
					std::cout << "local " << entity->name << " = entityManager:createEntity()" << std::endl;
					std::cout << entity->name << ".name = '" << entity->name << "'" << std::endl;
				}

				for (auto& comp : entity->components) {
					std::cout << comp->dump(entity->name) << std::endl;
				}
			}

			ImGui::TreePop();
			return true;
		}

		return false;
	}

	void EntityManagerWindow(std::string name, ECS::EntityManager& eManager) {
		Begin(name.c_str());
		if (ImGui::CollapsingHeader("Entities")){
			for (auto entity : eManager.entities) {
				if (entity->parent.expired()) {
					std::string header = CreateEntityHeaderString(entity);
					EntityNode(header, entity);
				}
			}
		}
		End();
	}
}