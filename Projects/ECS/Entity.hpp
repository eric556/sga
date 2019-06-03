#pragma once

#include <vector>
#include <memory>
#include <bitset>

#include "Component.hpp"

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

	template<class T>
	bool hasComponent(){
		T comp;
		return componentFlags.test(comp.type);
	}

	template<class T1, class T2, class... rest>
	bool hasComponents() {

		if (hasComponent<T1>()) {
			return true && hasComponents<T2, rest>();
		}

		return false;
	}

private:
	std::vector <std::shared_ptr<Component>> components;
	std::bitset<CompConst::maxComponents> componentFlags;
};