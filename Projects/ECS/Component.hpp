#pragma once

namespace CompConst {
	const int maxComponents = 128;

	enum ComponentType {
		BASE = 0,
	};
}

class Component {
public:
	Component() {};
	virtual ~Component() {};
#ifdef IMGUI_SFML
	virtual void debug() = 0;
#endif
	CompConst::ComponentType type = CompConst::ComponentType::BASE;
};