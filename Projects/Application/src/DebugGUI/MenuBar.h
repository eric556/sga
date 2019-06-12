#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include "../LuaInstance.h"
#include "LuaConsole.h"

#include <sol.hpp>

#include <vector>
#include <memory>

#include "GuiElement.h"

namespace Debug {
	class MenuBar : public GuiElement {
	public:
		MenuBar(Lua::LuaInstance& instance);
		void Draw();
	private:
		LuaConsole console;
		sol::state_view stateView;
	};
}