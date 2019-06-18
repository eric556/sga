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
		sf::IntRect textureRect;
		bool useTextureRect = false;
	private:
		char buffer[512];
		float origin[2] = { 0.0f, 0.0f };
		int textRectPosition[2] = { 0, 0 };
		int textRectSize[2] = { 0, 0 };
	};
}