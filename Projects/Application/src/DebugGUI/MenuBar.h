#pragma once
#include "../Engine/Game.h"
#include "LuaConsole.h"
#include "EntityCreator.h"
#include "StatefulElement.h"

namespace Debug {
	class MenuBar : public StatefulElement {
	public:
		MenuBar();
		void Draw(Game& game);
	private:
		LuaConsole console;
		EntityCreator entityCreator;
		bool isEntityManagerVisible = false;
	};
}