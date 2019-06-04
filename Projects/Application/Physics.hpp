#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>

#include "Constants.hpp"


class Physics : public ECS::Component {
public:
	Physics() {
		type = CompConsts::PHYSICS;
	}

	void debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		position_array[0] = position.x;
		position_array[1] = position.y;

		velocity_array[0] = velocity.x;
		velocity_array[1] = velocity.y;

		acceleration_array[0] = acceleration.x;
		acceleration_array[1] = acceleration.y;

		forceAccumulator_array[0] = forceAccumulator.x;
		forceAccumulator_array[1] = forceAccumulator.y;


		if (ImGui::DragFloat2("Position", position_array)) {
			position = sf::Vector2f(position_array[0], position_array[1]);
		}
		if (ImGui::DragFloat2("velocity", velocity_array)) {
			velocity = sf::Vector2f(velocity_array[0], velocity_array[1]);
		}
		if (ImGui::DragFloat2("acceleration", acceleration_array)) {
			acceleration = sf::Vector2f(acceleration_array[0], acceleration_array[1]);
		}
	}

public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f forceAccumulator;
	float mass;
private:
	float position_array[2] = {0.f, 0.f};
	float velocity_array[2] = { 0.f, 0.f };
	float acceleration_array[2] = { 0.f, 0.f };
	float forceAccumulator_array[2] = { 0.f, 0.f };
};