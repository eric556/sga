#pragma once
#include "StatefulElement.h"
#include <Entity.hpp>
#include <memory>


namespace Debug{
	class AnimationWindow : public StatefulElement {
	public:
		void Draw(Game & game);
	private:
		std::weak_ptr<ECS::Entity> currentEntity;
	};
}
