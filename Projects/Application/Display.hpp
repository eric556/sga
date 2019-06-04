#pragma once
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include <Component.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"

class Display : public ECS::Component {
public:
	Display() : shape() {
		type = CompConsts::DISPLAY;
	}

	Display(sf::Vector2f size, sf::Color color, float outlineThickness = 3.f) {
		shape = sf::RectangleShape(size);
		shape.setFillColor(sf::Color(color.r, color.g, color.b, color.a - 100));
		shape.setOutlineColor(color);
		shape.setOutlineThickness(outlineThickness);
	}

	~Display() {}

	void debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		color[0] = shape.getFillColor().r / 255.f;
		color[1] = shape.getFillColor().g / 255.f;
		color[2] = shape.getFillColor().b / 255.f;

		size[0] = shape.getSize().x;
		size[1] = shape.getSize().y;

		if (ImGui::ColorEdit3("Shape color", color)) {
			shape.setFillColor(sf::Color(static_cast<sf::Uint8>(color[0] * 255.f), static_cast<sf::Uint8>(color[1] * 255.f), static_cast<sf::Uint8>(color[2] * 255.f)));
		}

		if (ImGui::DragFloat2("Size", size)) {
			shape.setSize(sf::Vector2f(size[0], size[1]));
		}
	}
public:
	sf::RectangleShape shape;

private:
	float color[3] = { 0.f, 0.f, 0.f };
	float size[2] = { 0.0f, 0.0f };
};