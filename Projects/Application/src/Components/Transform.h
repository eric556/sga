#pragma once
#include <Component.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace Components {
	class Transform : public ECS::Component {
	public:
		Transform();

		void debug();

	public:
		sf::Vector3f position;
		float rotation;
		sf::Vector2f scale;

	private:
		float position_array[3] = { 0.f, 0.f, 0.0f };
		float scale_array[2] = { 0.f, 0.f};

	};
}