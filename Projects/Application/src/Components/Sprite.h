#pragma once
#include <Component.hpp>
#include <SFML/Graphics.hpp>


namespace Components {
	class Sprite : public ECS::Component {
	public:
		Sprite();

		void debug();
	public:
		std::string id;
		sf::Sprite sprite;
	private:
		char buffer[512];
		float origin[2] = { 0.0f, 0.0f };
	};
}