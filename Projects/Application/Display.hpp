#include "imgui.h"
#include "imgui-SFML.h"

#include <Component.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>

class Display : public Component {
public:
	Display() : shape() {}
	Display(sf::Vector2f size, sf::Color color, float outlineThickness = 3.f) {
		shape = sf::RectangleShape(size);
		shape.setFillColor(sf::Color(color.r, color.g, color.b, color.a - 100));
		shape.setOutlineColor(color);
		shape.setOutlineThickness(outlineThickness);
	}

	~Display() {}

	void debug() {
		ImGui::Text(std::to_string(this->type).c_str());
		std::string color = std::to_string(shape.getOutlineColor().r) + ", " + std::to_string(shape.getOutlineColor().g) + ", " + std::to_string(shape.getOutlineColor().b);
		ImGui::Text(color.c_str());
	}
public:
	sf::RectangleShape shape;
};