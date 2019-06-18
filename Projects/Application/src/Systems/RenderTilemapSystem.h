#pragma once
#include "../Resources/ResourceManager.h"

namespace Systems {
	class RenderTilemapSystem {
	public:
		void run(sf::RenderWindow& window, Assets::ResourceManager& rManager);
	};
}