#include "Sprite.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"
#include <sstream>

namespace Components {
	Sprite::Sprite() {
		type = SPRITE;
		name = "Sprite";
		buffer[0] = 0;
		id = "";
	}

	void Sprite::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		strcpy(buffer, id.c_str());

		textRectPosition[0] = textureRect.left;
		textRectPosition[1] = textureRect.top;

		textRectSize[0] = textureRect.width;
		textRectSize[1] = textureRect.height;

		if (ImGui::InputText("Texture Name", buffer, 512, ImGuiInputTextFlags_EnterReturnsTrue)) {
			id = std::string(buffer);
		}

		if (ImGui::DragFloat2("Origin", origin)) {
			sprite.setOrigin(sf::Vector2f(origin[0], origin[1]));
		}
		ImGui::Separator();
		ImGui::Checkbox("Use Texture Rect", &useTextureRect);

		if (ImGui::DragInt2("Position", textRectPosition)) {
			textureRect.left = textRectPosition[0];
			textureRect.top = textRectPosition[1];
		}

		if (ImGui::DragInt2("Size", textRectSize)) {
			textureRect.width = textRectSize[0];
			textureRect.height = textRectSize[1];
		}

	}

	std::string Sprite::dump(std::string name)
	{
		std::stringstream stream;

		stream << "local spriteComp" << name << " = " << name << ":addSprite()" << std::endl
			<< "spriteComp" << name << ".texture_id = '" << id << "'" << std::endl
			<< "spriteComp" << name << ".useTextureRect = " << ((useTextureRect) ? "true" : "false") << std::endl
			<< "spriteComp" << name << ".textureRect = IntRect.new(" << textureRect.left << ", " << textureRect.top << ", " << textureRect.width << ", " << textureRect.height << ")" << std::endl;

		return stream.str();
	}
}