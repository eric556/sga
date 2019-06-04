#pragma once
#include <memory>
#include <vector>
#include <iostream>

#include "Entity.hpp"

class EntityManager {
public:
	std::shared_ptr<Entity> createEntity() {

		std::shared_ptr<Entity> newEntity(new Entity(++entityCount));

		entities.push_back(newEntity);
		return entities.back();
	}

	std::shared_ptr<Entity> addEntity(Entity entity) {
		std::shared_ptr<Entity> newEntity(new Entity(entity));
		newEntity->id = ++entityCount;
		entities.push_back(newEntity);

		return entities.back();
	}

	// maybe do this with binary search since all the IDs should be in order
	bool deleteEntity(unsigned int id) {
		for (int i = 0; i < entities.size(); i++) {
			if (entities[i]->id == id) {
				entities.erase(entities.begin() + i);
				return true;
			}
		}

		return false;
	}

	std::shared_ptr<Entity> getEntityByID(unsigned int id) {
		for (auto& entity : entities) {
			if (entity->id == id) {
				return entity;
			}
		}

		return nullptr;
	}

	template<class T>
	std::vector<std::shared_ptr<Entity>> getEntitiesByComponent() {
		std::vector<std::shared_ptr<Entity>> retEntities;

		for (auto entity : entities) {
			if (entity->hasComponent<T>()) {
				retEntities.push_back(entity);
			}
		}

		return retEntities;
	}

	template<class T, class... Other>
	std::vector<std::shared_ptr<Entity>> getEntitiesByComponents() {
		std::vector<std::shared_ptr<Entity>> retEntities;

		for (auto entity : entities) {
			if (entity->hasComponent<T, Other...>()) {
				retEntities.push_back(entity);
			}
		}

		return retEntities;
	}

#ifdef IMGUI_SFML
	void Debug() {
		if (!ImGui::CollapsingHeader("Entities"))
			return;
		for(auto entity : entities) {
			std::string entityHeader = "Entity " + std::to_string(entity->id);
			if (ImGui::TreeNode(entityHeader.c_str())) {
				entity->Debug();
				ImGui::TreePop();
			}
		}
	}
#endif // IMGUI_SFML


public:
	static inline std::vector<std::shared_ptr<Entity>> entities;
	static inline unsigned int entityCount;
};