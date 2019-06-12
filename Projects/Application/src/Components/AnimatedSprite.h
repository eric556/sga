#pragma once

#include <Component.hpp>
#include <SFML/Graphics.hpp>
#include <string>


namespace Components {
	class AnimatedSprite : public ECS::Component {
	public:
		AnimatedSprite();
		void debug();
	public:
		std::string id;
		sf::Sprite sprite;
	private:
		char buffer[512];
		float origin[2] = { 0.0f, 0.0f };
	};
}