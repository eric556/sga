#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"


namespace Components {
	class Friction : public ECS::Component {
	public:
		Friction() {
			type = FRICTION;
			name = "Friction";
			frictionCoff = 1.0f;
			normal = sf::Vector3f(0.0f, 0.0f, 0.0f);
		}

		void debug() {
			ImGui::DragFloat("Coeff", &frictionCoff);
			ImGui::Text(std::to_string(normal.x).c_str());
			ImGui::SameLine();
			ImGui::Text(std::to_string(normal.y).c_str());
			ImGui::SameLine();
			ImGui::Text(std::to_string(normal.z).c_str());
		}

	public:
		float frictionCoff;
		sf::Vector3f normal;
	};
}