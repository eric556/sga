#include "Camera.h"
#include "../Constants.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <sstream>

Components::Camera::Camera()
{
	type = CAMERA;
	name = "Camera";
	view.setCenter(0.f, 0.f);
	view.setSize(600.f, 400.f);
}

void Components::Camera::debug()
{
	ImGui::Text(std::to_string(this->type).c_str());

	position[0] = view.getCenter().x;
	position[1] = view.getCenter().y;

	size[0] = view.getSize().x;
	size[1] = view.getSize().y;

	if (ImGui::DragFloat2("Position", position)) {
		view.setCenter(position[0], position[1]);
	}

	if (ImGui::DragFloat2("Size", size)) {
		view.setSize(size[0], size[1]);
	}

	if (ImGui::Button("Zoom In", sf::Vector2f(100.0f, 40.f))) {
		view.setSize(view.getSize().x - 1, view.getSize().y - 1);
	}

	if (ImGui::Button("Zoom Out", sf::Vector2f(100.0f, 40.f))) {
		view.setSize(view.getSize().x + 1, view.getSize().y + 1);
	}
}

std::string Components::Camera::dump(std::string name)
{
	std::stringstream stream;
	stream << "local cameraComp" << name << " = " << name << ":addCamera()" << std::endl
		<< "cameraComp" << name << ":setSize(" << view.getSize().x << ", " << view.getSize().y << ")" << std::endl;
	return stream.str();
}
