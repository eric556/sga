#include "AnimatedSprite.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"


namespace Components {
	AnimatedSprite::AnimatedSprite() {
		type = ANIMATED_SPRITE;
		name = "Animated Sprite";
		buffer[0] = 0;
		id = "";
	}

	void AnimatedSprite::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		strcpy(buffer, id.c_str());

		if (ImGui::InputText("Texture Name", buffer, 512, ImGuiInputTextFlags_EnterReturnsTrue)) {
			id = std::string(buffer);
		}

		if (ImGui::DragFloat2("Origin", origin)) {
			sprite.setOrigin(sf::Vector2f(origin[0], origin[1]));
		}
	}
}