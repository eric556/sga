#pragma once
#include<string>

namespace ECS {
	class Component {
	public:
		Component() {};
		virtual ~Component() {};
		virtual void debug() = 0;
		unsigned int type = 0;
		std::string name = "Base";
	};
}