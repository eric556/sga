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
	virtual void debug() = 0;
	CompConst::ComponentType type = CompConst::ComponentType::BASE;
};