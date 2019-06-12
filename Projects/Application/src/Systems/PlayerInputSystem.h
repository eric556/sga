#pragma once
#include <SFML/Graphics.hpp>


namespace Systems {
	class PlayerInputSystem {
	public:
		void run(float dt, sf::RenderWindow& window);
	};
}
