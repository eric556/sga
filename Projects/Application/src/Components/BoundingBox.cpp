#include "BoundingBox.h"
#include "../Constants.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include <sstream>

Components::BoundingBox::BoundingBox()
{
	type = BOUNDING_BOX;
	name = "Bounding Box";
	display = false;
}

void Components::BoundingBox::debug()
{
	ImGui::Text(std::to_string(this->type).c_str());

	boundingBoxPos[0] = boundingBox.left;
	boundingBoxPos[1] = boundingBox.top;

	boundingBoxSize[0] = boundingBox.width;
	boundingBoxSize[1] = boundingBox.height;

	if (ImGui::DragFloat2("Position", boundingBoxPos)) {
		boundingBox.left = boundingBoxPos[0];
		boundingBox.top = boundingBoxPos[1];
	}

	if (ImGui::DragFloat2("Size", boundingBoxSize)) {
		boundingBox.width = boundingBoxSize[0];
		boundingBox.height = boundingBoxSize[1];
	}

	if (ImGui::Checkbox("Display", &display)) {

	}
}

std::string Components::BoundingBox::dump(std::string name)
{
	std::stringstream stream;
	stream << "local boundingBoxComp" << name << " = " << name << ":addBoundingBox()" << std::endl 
		   << "boundingBoxComp" << name << ".rect = FloatRect.new(" << boundingBox.left << ", " << boundingBox.top << ", " << boundingBox.width << ", " << boundingBox.height << ")" << std::endl;
	return stream.str();
}
