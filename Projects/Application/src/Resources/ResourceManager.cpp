#include "ResourceManager.h"

namespace Assets {
	bool ResourceManager::LoadTexture(const std::string& id, const std::string& path) {
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		if (!texture->loadFromFile(path)) {
			return false;
		}
		textureManager.addAsset(id, texture);
		return true;
	}
}