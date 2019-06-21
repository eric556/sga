#pragma once

#include <Component.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>


namespace Components {
	struct Frame {
		int x;
		int y;
		int width;
		int height;
		float time;
	};

	class AnimatedSprite : public ECS::Component {
	public:
		AnimatedSprite();
		void debug();
		std::string dump(std::string name);
		void setAnimation(std::string name, std::vector<Frame> anim);
		Frame getCurrentFrame();
		void update(float dt);
		void setCurrentAnimation(std::string anim);
	public:
		std::string id;
		sf::Sprite sprite;
		std::string currentAnimation;
		float animationTimer = 0;
		int currentAnimationFrame = 0;
	private:
		char buffer[256];
		char currentAnimBuffer[256];
		float origin[2] = { 0.0f, 0.0f };
		std::unordered_map<std::string, std::vector<Frame>> animationMap;
	};
}