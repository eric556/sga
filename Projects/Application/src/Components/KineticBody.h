#pragma once

#include <Component.hpp>
#include <SFML/Graphics.hpp>


namespace Components {
	class KineticBody : public ECS::Component {
	public:
		KineticBody();

		void debug();
		std::string dump(std::string name);

	public:
		sf::Vector3f velocity;
		sf::Vector3f acceleration;
		sf::Vector3f forceAccumulator;
		float mass;
	private:
		float velocity_array[3] = { 0.f, 0.f, 0.0f };
		float acceleration_array[3] = { 0.f, 0.f, 0.0f };
		float forceAccumulator_array[3] = { 0.f, 0.f, 0.0f };
	};
}
