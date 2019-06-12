#pragma once
#include <string>
#include <Component.hpp>
#include <SFML/Graphics.hpp>

namespace Components {
	class Input : public ECS::Component {
	public:
		Input();
		void debug();
	public:
		float speed;
	};
}