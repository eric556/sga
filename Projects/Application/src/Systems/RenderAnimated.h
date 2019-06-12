#pragma once
#include "../Resources/ResourceManager.h"

namespace Systems {
	class RenderAnimated {
	public:
		void run(float dt, sf::RenderWindow& window, Assets::ResourceManager& rManager);
	};
}