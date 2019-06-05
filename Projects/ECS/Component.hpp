#pragma once
#include<string>

namespace ECS {
	class Component {
	public:
		Component() {};
		virtual ~Component() {};
#ifdef IMGUI_SFML
		virtual void debug() = 0;
#endif
		unsigned int type = 0;
		std::string name = "Base";
	};
}