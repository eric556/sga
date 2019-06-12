#pragma once
#include <SFML/Graphics.hpp>

#include "AssetManager.hpp"

namespace Assets {
	class ResourceManager {
	public:
		bool LoadTexture(const std::string& id, const std::string& path);

		template<class T>
		std::shared_ptr<T> getAsset(const std::string& id) {
			return nullptr;
		}

		template <>
		std::shared_ptr<sf::Texture> getAsset(const std::string& id) {
			return textureManager.getAsset(id);
		}

	private:
		AssetManager<sf::Texture> textureManager;
	};
}