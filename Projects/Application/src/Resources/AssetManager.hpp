#pragma once
#include <memory>
#include <unordered_map>

namespace Assets {
	template<class T>
	class AssetManager {
	public:
		void addAsset(const std::string& id, std::shared_ptr<T> asset) {
			if (assetMap.find(id) == assetMap.end()) {
				assetMap[id] = asset;
			}
		}

		std::shared_ptr<T> getAsset(const std::string& id) {
			if (assetMap.find(id) == assetMap.end()) {
				return nullptr;
			}

			return assetMap[id];
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<T>> assetMap;
	};
}