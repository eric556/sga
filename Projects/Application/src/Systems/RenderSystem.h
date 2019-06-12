#pragma once

#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>


namespace Systems {
	class RenderSystem {
	public:
		void run(sf::RenderWindow& window);
	};
}
