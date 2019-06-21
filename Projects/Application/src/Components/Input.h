#pragma once
#include <string>
#include <Component.hpp>
#include <SFML/Graphics.hpp>

namespace Components {
	class Input : public ECS::Component {
	public:
		Input();
		void debug();
		std::string dump(std::string name);
	public:
		float speed;
	};
}