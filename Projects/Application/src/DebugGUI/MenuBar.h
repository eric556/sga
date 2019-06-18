#pragma once
#include "../Engine/Game.h"
#include "LuaConsole.h"

namespace Debug {
	class MenuBar {
	public:
		MenuBar();
		void Draw(Game& game);
	private:
		LuaConsole console;
		bool isConsoleVisible = false;
		bool isEntityManagerVisible = false;
	};
}