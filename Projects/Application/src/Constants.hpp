#pragma once

namespace Components{
	enum ComponentType {
		BASE = 0,
		DISPLAY,
		KINETIC_BODY,
		GRAVITY,
		INPUT,
		MOVEABLE,
		DRAG,
		FRICTION,
		TRANSFORM,
		SPRITE,
		ANIMATED_SPRITE,
		TILE_MAP,
		BOUNDING_BOX,
		CAMERA,
		STATE
	};

	static const float MIN_MASS = 0.0001f;
}

namespace Math {
	const float  PI_F = 3.14159265358979f;
	const float RADIAN_TO_DEGREES = 180.f / PI_F;
}
