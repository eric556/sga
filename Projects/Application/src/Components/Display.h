#pragma once
#include <string>
#include <Component.hpp>
#include <SFML/Graphics.hpp>


namespace Components {
	class Display : public ECS::Component {
	public:
		Display();
		void debug();
	public:
		sf::RectangleShape shape;

	private:
		float color[3] = { 0.f, 0.f, 0.f };
		float size[2] = { 0.0f, 0.0f };
		float origin[2] = { 0.0f, 0.0f };
	};
}
