#pragma once

#include <vector>
#include <string>
#include <sol.hpp>

#include "../LuaInstance.h"
#include "../Engine/Game.h"
#include "StatefulElement.h"
#include "FilePicker.h"

namespace Debug {
	class LuaConsole : public StatefulElement{
	public:
		LuaConsole();
		void Draw(Game& game);
	private:
		char textBuffer[255];
		char filePathBuffer[255];
		FilePicker scriptFilePicker;
		std::vector <std::string> entries;
	};
}
