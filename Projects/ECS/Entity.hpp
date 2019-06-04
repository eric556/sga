#pragma once

#include <vector>
#include <memory>
#include <bitset>

#ifdef IMGUI_SFML
#include "imgui.h"
#include "imgui-SFML.h"
#endif // IMGUI_SFML

#ifndef MAX_COMPONENTS
#define MAX_COMPONENTS 128
#endif // !MAX_COMPONENTS


#include "Component.hpp"

namespace ECS {
	class Entity {
	public:
		unsigned int id;

		Entity(unsigned int id = 0) {
			this->id = id;
		}

		template<class T>
		std::shared_ptr<T> addComponent() {
			T comp;
			componentFlags.set(comp.type);
			components.push_back(std::shared_ptr<Component>(new T()));

			return std::static_pointer_cast<T>(components.back());
		}

		void addComponent(unsigned int flag) {
			componentFlags.set(flag);
		}

		template<class T>
		std::shared_ptr<T> getComponent() {
			T comp;

			for (int i = 0; i < components.size(); i++) {
				if (components[i]->type == comp.type) {
					return std::static_pointer_cast<T>(components[i]);
				}
			}

			return nullptr;
		}

		bool hasComponent(unsigned int flag) {
			return componentFlags.test(flag);
		}

		bool hasComponents(unsigned int flags[], int numFlags) {
			bool toReturn = true;

			for (int i = 0; i < numFlags; i++) {
				toReturn &= hasComponent(flags[i]);
			}

			return toReturn;
		}

		template<class T>
		bool hasComponent() {
			T comp;
			return componentFlags.test(comp.type);
		}

		template<class T>bool hasComponents() {
			return this->hasComponent<T>();
		}

		template<class T1, class T2, class... rest>
		bool hasComponents() {

			if (hasComponent<T1>()) {
				return true && hasComponents<T2, rest...>();
			}

			return false;
		}

		template<class T1>
		bool hasComponents(unsigned int flag) {
			if (!hasComponent(flag)) return false;

			return hasComponents<T1>();
		}

		template<class T1>
		bool hasComponents(unsigned int flags[], int numFlags) {
			if (!hasComponents(flags, numFlags)) return false;

			return hasComponents<T1>();
		}

		template<class T1, class T2, class... rest>
		bool hasComponents(unsigned int flag) {
			if (!hasComponent(flag)) return false;

			return hasComponents<T1, T2, rest>();
		}

		template<class T1, class T2, class... rest>
		bool hasComponents(unsigned int flags[], int numFlags) {
			if (!hasComponents(flags, numFlags)) return false;

			return hasComponents<T1, T2, rest>();
		}

#ifdef IMGUI_SFML
		void Debug() {
			if (ImGui::TreeNode("Components")) {
				for (auto component : components) {
					if (ImGui::TreeNode(std::to_string(component->type).c_str())) {
						component->debug();
						ImGui::TreePop();
					}
				}
				ImGui::TreePop();
			}
		}
#endif // IMGUI_SFML


	private:
		std::vector <std::shared_ptr<Component>> components;
		std::bitset<MAX_COMPONENTS> componentFlags;
	};
}