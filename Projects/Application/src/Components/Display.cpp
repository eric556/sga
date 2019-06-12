#include "Display.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"


namespace Components {
	Display::Display() : shape() {
		type = DISPLAY;
		name = "Display";
	}

	void Display::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		color[0] = shape.getFillColor().r / 255.f;
		color[1] = shape.getFillColor().g / 255.f;
		color[2] = shape.getFillColor().b / 255.f;

		size[0] = shape.getSize().x;
		size[1] = shape.getSize().y;

		origin[0] = shape.getOrigin().x;
		origin[1] = shape.getOrigin().y;


		if (ImGui::ColorEdit3("Shape color", color)) {
			shape.setFillColor(sf::Color(static_cast<sf::Uint8>(color[0] * 255.f), static_cast<sf::Uint8>(color[1] * 255.f), static_cast<sf::Uint8>(color[2] * 255.f)));
		}

		if (ImGui::DragFloat2("Size", size)) {
			shape.setSize(sf::Vector2f(size[0], size[1]));
		}

		if (ImGui::DragFloat2("Origin", origin)) {
			shape.setOrigin(sf::Vector2f(origin[0], origin[1]));
		}

	}
}