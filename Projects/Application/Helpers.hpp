#pragma once
#include <SFML/Graphics.hpp>

namespace Math {
	static inline float mag(const sf::Vector3f& vec) {
		return std::sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}

	static inline sf::Vector3f normalize(const sf::Vector3f& vec) {
		float magnitude = mag(vec);
		if (magnitude == 0.0f) return sf::Vector3f(0.0f, 0.0f, 0.0f);
		return vec / magnitude;
	}
}