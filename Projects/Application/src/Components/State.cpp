#include "State.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../Constants.hpp"
#include <sstream>

Components::State::State()
{
	type = STATE;
	name = "State";
	buffer[0] = 0;
	currentState = "";
	currentItem = 0;
}

void Components::State::debug()
{
	ImGui::Text(std::to_string(this->type).c_str());

	strcpy(buffer, currentState.c_str());

	std::stringstream stream;
	for (auto kv : stateFunctions) {
		stream << kv.first << "\0";
	}

	ImGui::Combo("Current State", &currentItem, stream.str().c_str());

}

std::string Components::State::dump(std::string name)
{
	std::stringstream stream;
	stream << "local stateComp" << name << " = " << name << ":addState()" << std::endl;
	return stream.str();
}

std::string Components::State::setState(std::string newState)
{
	std::string old = currentState;
	currentState = newState;
	return old;
}
