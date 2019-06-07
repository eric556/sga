#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Constants.hpp"
#include "LuaInstance.hpp"

namespace Components {
	class Transform : public ECS::Component {
	public:
		Transform() {
			type = TRANSFORM;
			name = "Transform";
			position = sf::Vector3f(0.0f, 0.0f, 0.0f);
			scale = sf::Vector2f(1.0f, 1.0f);
			rotation = 0.f;
		}

		void debug() {
			ImGui::Text(std::to_string(this->type).c_str());

			position_array[0] = position.x;
			position_array[1] = position.y;
			position_array[2] = position.z;

			scale_array[0] = scale.x;
			scale_array[1] = scale.y;

			if (ImGui::DragFloat3("Position", position_array)) {
				position = sf::Vector3f(position_array[0], position_array[1], position_array[2]);
			}

			if (ImGui::DragFloat2("Scale", scale_array)) {
				scale = sf::Vector2f(scale_array[0], scale_array[1]);
			}

			if (ImGui::SliderFloat("Rotation", &rotation, 0.f, 360.f)) {

			}
		}

	public:
		sf::Vector3f position;
		float rotation;
		sf::Vector2f scale;

	private:
		float position_array[3] = { 0.f, 0.f, 0.0f };
		float scale_array[2] = { 0.f, 0.f};

	};
}