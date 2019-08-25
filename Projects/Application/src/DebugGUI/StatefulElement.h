#pragma once
#include "../Engine/Game.h"


namespace Debug {
	class StatefulElement {
	public:
		virtual void Draw(Game& game) = 0;
		bool isVisible = false;
	};
}
