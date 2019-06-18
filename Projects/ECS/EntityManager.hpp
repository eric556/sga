#pragma once
#include <memory>
#include <vector>
#include <iostream>

#include "Entity.hpp"

namespace ECS {
	class EntityManager {
	public:
		std::shared_ptr<Entity> createEntity() {

			std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(++entityCount);

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

		std::shared_ptr<Entity> getEntityByName(std::string name) {
			for (auto& entity : entities) {
				if (entity->name == name) {
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
				if (entity->hasComponents<T, Other...>()) {
					retEntities.push_back(entity);
				}
			}

			return retEntities;
		}

		template<class T>
		std::vector<std::shared_ptr<Entity>> getEntitiesByComponent(unsigned int flags[], int numFlags) {
			std::vector<std::shared_ptr<Entity>> retEntities;

			for (auto entity : entities) {
				if (entity->hasComponents<T>(flags, numFlags)) {
					retEntities.push_back(entity);
				}
			}

			return retEntities;
		}

		template<class T, class... Other>
		std::vector<std::shared_ptr<Entity>> getEntitiesByComponents(unsigned int flags[], int numFlags) {
			std::vector<std::shared_ptr<Entity>> retEntities;

			for (auto entity : entities) {
				if (entity->hasComponents<T, Other...>(flags, numFlags)) {
					retEntities.push_back(entity);
				}
			}

			return retEntities;
		}

		template<class T>
		std::vector<std::shared_ptr<Entity>> getEntitiesByComponent(unsigned int flag) {
			std::vector<std::shared_ptr<Entity>> retEntities;

			for (auto entity : entities) {
				if (entity->hasComponents<T>(flag)) {
					retEntities.push_back(entity);
				}
			}

			return retEntities;
		}

		template<class T, class... Other>
		std::vector<std::shared_ptr<Entity>> getEntitiesByComponents(unsigned int flag) {
			std::vector<std::shared_ptr<Entity>> retEntities;

			for (auto entity : entities) {
				if (entity->hasComponents<T, Other...>(flag)) {
					retEntities.push_back(entity);
				}
			}

			return retEntities;
		}

	public:
		static inline std::vector<std::shared_ptr<Entity>> entities;
		static inline unsigned int entityCount;
	};
}