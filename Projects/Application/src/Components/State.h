#pragma once
#include <Component.hpp>
#include <functional>
#include <map>

namespace Components {
	class State : public ECS::Component {
	public:
		State();
		void debug();
		std::string dump(std::string name);
		std::string setState(std::string newState);
	public:
		std::unordered_map<std::string, std::function<std::string(std::string)>> stateFunctions;
		std::string currentState;
	private:
		char buffer[256];
		int currentItem;
	};
}