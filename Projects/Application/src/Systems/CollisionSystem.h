#pragma once
#include <SFML/Graphics.hpp>
#include "../Engine/Game.h"

namespace Systems {
	class CollisionSystem {
	public:
		void run(Game& game);
	};
}