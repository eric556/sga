#pragma once

#include "LuaInstance.hpp"
#include "Components.h"

namespace Components {
	static void RegisterComponents(){
		Lua::LuaInstance::registerComponent<Display>("Display");
		Lua::LuaInstance::registerComponent<Drag>("Drag");
		Lua::LuaInstance::registerComponent<Friction>("Friction");
		Lua::LuaInstance::registerComponent<Input>("Input");
		Lua::LuaInstance::registerComponent<KineticBody>("KineticBody");
		Lua::LuaInstance::registerComponent<Transform>("Transform");
	}
}