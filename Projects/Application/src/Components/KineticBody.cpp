#include "KineticBody.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"


namespace Components {
	KineticBody::KineticBody() {
		type = KINETIC_BODY;
		mass = MIN_MASS;
		name = "Kinetic Body";
	}

	void KineticBody::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		velocity_array[0] = velocity.x;
		velocity_array[1] = velocity.y;
		velocity_array[2] = velocity.z;

		acceleration_array[0] = acceleration.x;
		acceleration_array[1] = acceleration.y;
		acceleration_array[2] = acceleration.z;

		forceAccumulator_array[0] = forceAccumulator.x;
		forceAccumulator_array[1] = forceAccumulator.y;
		forceAccumulator_array[2] = forceAccumulator.z;

		if (ImGui::DragFloat3("velocity", velocity_array)) {
			velocity = sf::Vector3f(velocity_array[0], velocity_array[1], velocity_array[2]);
		}

		if (ImGui::DragFloat3("acceleration", acceleration_array)) {
			acceleration = sf::Vector3f(acceleration_array[0], acceleration_array[1], acceleration_array[2]);
		}

		if (ImGui::DragFloat("mass", &mass, 1.0f, MIN_MASS, 1000.0f)) {
		}
	}
}