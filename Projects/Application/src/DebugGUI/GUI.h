#pragma once
#include <EntityManager.hpp>

namespace ImGui {
	std::string CreateEntityHeaderString(std::shared_ptr<ECS::Entity> entity);
	bool EntityNode(std::string name, std::shared_ptr<ECS::Entity> entity);
	void EntityManagerWindow(std::string name, ECS::EntityManager& eManager);
}