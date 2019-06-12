#include "ComponentRegister.h"
#include "Display.h"
#include "Input.h"
#include "KineticBody.h"
#include "Transform.h"
#include "Sprite.h"
#include "AnimatedSprite.h"


namespace Components {

	void ComponenetRegister::RegisterComponents(Lua::LuaInstance& instance)
	{
		auto displayType = instance.registerComponent<Display>("Display");
		displayType.set("shape", &Components::Display::shape);

		auto inputType = instance.registerComponent<Input>("Input");
		inputType.set("speed", &Components::Input::speed);

		auto kineticBody = instance.registerComponent<KineticBody>("KineticBody");
		kineticBody.set("velocity", &Components::KineticBody::velocity);
		kineticBody.set("acceleration", &Components::KineticBody::acceleration);
		kineticBody.set("forceAccumulator", &Components::KineticBody::forceAccumulator);
		kineticBody.set("mass", &Components::KineticBody::mass);

		auto transformType = instance.registerComponent<Transform>("Transform");
		transformType.set("position", &Components::Transform::position);
		transformType.set("scale", &Components::Transform::scale);
		transformType.set("rotation", &Components::Transform::rotation);

		auto textureType = instance.registerComponent<Sprite>("Sprite");
		textureType.set("texture_id", &Components::Sprite::id);

		auto animatedSpriteType = instance.registerComponent<AnimatedSprite>("AnimatedSprite");
		animatedSpriteType.set("texture_id", &Components::AnimatedSprite::id);
	}
}