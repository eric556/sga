#pragma once

#include <SFML/Graphics.hpp>
#include "../Resources/ResourceManager.h"

namespace Systems {
	class RenderSpriteSystem {
	public:
		void run(sf::RenderWindow& window, Assets::ResourceManager& rManager);
	};
}
