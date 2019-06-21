#pragma once
#include <SFML/Graphics.hpp>
#include <Component.hpp>
#include <Entity.hpp>

namespace Components {
	class Camera : public ECS::Component {
	public:
		Camera();
		void debug();
		std::string dump(std::string name);
	public:
		sf::View view;
		std::weak_ptr<ECS::Entity> followEntity;
	private:
		float position[2] = { 0.f, 0.f };
		float size[2] = { 0.f, 0.f };
		float zoom = 1.0f;
	};
}