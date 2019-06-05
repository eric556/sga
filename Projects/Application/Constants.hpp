#pragma once

namespace Components{
	enum ComponentType {
		BASE = 0,
		DISPLAY,
		PHYSICS,
		GRAVITY,
		INPUT,
		MOVEABLE,
		DRAG
	};

	static const float MIN_MASS = 0.0001f;
}
