#pragma once

#include "../LuaInstance.h"

namespace Components {
	class ComponenetRegister {
	public:
		static void RegisterComponents(Lua::LuaInstance& instance);
	};
}