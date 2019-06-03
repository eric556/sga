#pragma once
#include <memory>
#include <vector>

#include "Entity.hpp"

class EntityManager {
public:
	EntityManager() {}

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

	std::vector<std::shared_ptr<Entity>>& getEntities() {
		return entities;
	}

private:
	static std::vector<std::shared_ptr<Entity>> entities;
	static unsigned int entityCount;
};