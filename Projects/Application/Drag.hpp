#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"


namespace Components {
	class Drag : public ECS::Component {
	public:
		Drag() {
			type = DRAG;
			name = "Drag";
			dragCoff = 0.0f;
		}

		void debug() {
			ImGui::Text(std::to_string(dragCoff).c_str());
		}

	public:
		float dragCoff;

	};
}