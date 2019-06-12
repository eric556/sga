#pragma once

#include <vector>
#include <string>
#include <sol.hpp>

#include "../LuaInstance.h"
#include "GuiElement.h"

namespace Debug {
	class LuaConsole : public GuiElement{
	public:
		LuaConsole(Lua::LuaInstance& instance);
		void Draw();
	private:
		char textBuffer[255];
		char filePathBuffer[255];
		std::vector<std::string> entries;
		sol::state_view stateView;
	};
}
