#include  "Input.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"


namespace Components {
	Input::Input() {
		type = INPUT;
		name = "Input";
		speed = 0.0f;
	}

	void Input::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		if (ImGui::DragFloat("Speed", &speed)) {

		}
	}
}