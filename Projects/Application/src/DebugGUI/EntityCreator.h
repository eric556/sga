#pragma once

#include "StatefulElement.h"
#include <memory>
#include <Entity.hpp>

namespace Debug {
	class EntityCreator : public StatefulElement {
	public:
		void Draw(Game & game);
	private:
		std::weak_ptr<ECS::Entity> currentEntity;
	};
}