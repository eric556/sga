#include "AnimatedSprite.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"


namespace Components {
	AnimatedSprite::AnimatedSprite() {
		type = ANIMATED_SPRITE;
		name = "Animated Sprite";
		buffer[0] = 0;
		currentAnimBuffer[0] = 0;
		id = "";
		currentAnimation = "idle";
	}

	void AnimatedSprite::debug() {
		ImGui::Text(std::to_string(this->type).c_str());

		strcpy(buffer, id.c_str());
		strcpy(currentAnimBuffer, currentAnimation.c_str());
		origin[0] = sprite.getOrigin().x;
		origin[1] = sprite.getOrigin().y;

		if (ImGui::InputText("Texture Name", buffer, 256, ImGuiInputTextFlags_EnterReturnsTrue)) {
			id = std::string(buffer);
		}

		if (ImGui::DragFloat2("Origin", origin)) {
			sprite.setOrigin(sf::Vector2f(origin[0], origin[1]));
		}

		if (ImGui::InputText("Current Animation", currentAnimBuffer, 256, ImGuiInputTextFlags_EnterReturnsTrue)) {
			currentAnimation = std::string(currentAnimBuffer);
		}

		ImGui::DragFloat("Animation Timer", &animationTimer, 0.001f, 0.0f);
		ImGui::SliderInt("Current Frame", &currentAnimationFrame, 0, animationMap[currentAnimation].size() - 1);

		if (!ImGui::CollapsingHeader("Frames")) {
			return;
		}

		for (auto& kv : animationMap) {
			std::string name = kv.first;
			if (ImGui::TreeNode(name.c_str())) {
				std::vector<Frame> frames = kv.second;
				for (int i = 0; i < frames.size(); i++) {
					if (ImGui::TreeNode(std::to_string(i).c_str())) {
						ImGui::DragInt2("Position", &kv.second[i].x);
						ImGui::DragInt2("Size", &kv.second[i].width);
						ImGui::DragFloat("time", &kv.second[i].time);

						ImGui::TreePop();
					}
				}
				ImGui::TreePop();
			}
		}
	}

	std::string AnimatedSprite::dump(std::string name)
	{
		// TODO finish this
		return "-- Animated Sprite not implemented\r\n";
	}

	void AnimatedSprite::setAnimation(std::string name, std::vector<Frame> anim)
	{
		// Maybe do some error checking here
		animationMap[name] = anim;
	}

	Frame AnimatedSprite::getCurrentFrame()
	{
		Frame current = animationMap[currentAnimation][currentAnimationFrame];
		return current;
	}

	void AnimatedSprite::update(float dt)
	{
		if (animationTimer > getCurrentFrame().time) {
			if (currentAnimationFrame < animationMap[currentAnimation].size() - 1) {
				currentAnimationFrame++;
			}
			else {
				currentAnimationFrame = 0;
			}
			animationTimer = 0;
		}
		else {
			animationTimer += dt;
		}
	}

	void AnimatedSprite::setCurrentAnimation(std::string anim)
	{
		if (currentAnimation != anim) {
			currentAnimation = anim;
			currentAnimationFrame = 0;
		}
	}
}