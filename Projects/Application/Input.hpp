#pragma once
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"

namespace Components {
	class Input : public ECS::Component {
	public:
		Input() {
			type = INPUT;
			name = "Input";
			speed = 0.0f;
		}

		void debug() {
			ImGui::Text(std::to_string(this->type).c_str());

			if (ImGui::DragFloat("Speed", &speed)) {

			}
		}
	public:
		float speed;
	};
}