#pragma once

#include <EntityManager.hpp>
#include "../Components/KineticBody.h"
#include "../Constants.hpp"


namespace Systems {
	class GravitySystem {
	public:
		void run();
	};

	static const inline float GRAV_CONST = 9.81f;
}