#pragma once
#include "../Engine/Game.h"

namespace Systems {
	class RenderAnimated {
	public:
		void run(float dt, Game& game);
	};
}