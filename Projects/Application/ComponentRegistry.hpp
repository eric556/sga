#pragma once

#include "LuaInstance.hpp"
#include "Components.h"

namespace Components {
	static void RegisterComponents(){
		auto displayType = Lua::LuaInstance::registerComponent<Display>("Display");
		displayType.set("shape", &Components::Display::shape);

		auto dragType = Lua::LuaInstance::registerComponent<Drag>("Drag");
		auto frictionType = Lua::LuaInstance::registerComponent<Friction>("Friction");

		auto inputType = Lua::LuaInstance::registerComponent<Input>("Input");
		inputType.set("speed", &Components::Input::speed);

		auto kineticBody = Lua::LuaInstance::registerComponent<KineticBody>("KineticBody");
		kineticBody.set("velocity", &Components::KineticBody::velocity);
		kineticBody.set("acceleration", &Components::KineticBody::acceleration);
		kineticBody.set("forceAccumulator", &Components::KineticBody::forceAccumulator);
		kineticBody.set("mass", &Components::KineticBody::mass);

		auto transformType = Lua::LuaInstance::registerComponent<Transform>("Transform");
		transformType.set("position", &Components::Transform::position);
		transformType.set("scale", &Components::Transform::scale);
		transformType.set("rotation", &Components::Transform::rotation);
	}
}