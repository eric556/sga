#pragma once

#include <vector>
#include <string>
#include <sol.hpp>

#include "../LuaInstance.h"
#include "../Engine/Game.h"

namespace Debug {
	class LuaConsole {
	public:
		LuaConsole();
		void Draw(Game& game);
	private:
		char textBuffer[255];
		char filePathBuffer[255];
		std::vector<std::string> entries;
	};
}
