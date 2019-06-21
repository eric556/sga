#include "imgui.h"
#include "imgui-SFML.h"
#include "TileMap.h"
#include "../Constants.hpp"

Components::TileMap::TileMap()
{
	type = TILE_MAP;
	name = "Tile Map";
	buffer[0] = 0;
	tilesetId = "";
}

void Components::TileMap::debug()
{
	ImGui::Text(std::to_string(this->type).c_str());
	strcpy(buffer, tilesetId.c_str());

	if (ImGui::InputText("Tileset Name", buffer, 256, ImGuiInputTextFlags_EnterReturnsTrue)) {
		tilesetId = std::string(buffer);
	}
}

void Components::TileMap::setMap(int width, int height, std::map<int, std::vector<std::vector<Tile>>> tiles) {

	for (auto& kv : tiles) {
		layers[kv.first] = sf::VertexArray(sf::Quads, width * height * 4);

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				Tile current = kv.second[y][x];
				sf::Vertex* quad = &layers[kv.first][(y + x * width) * 4];
				quad[0].position = sf::Vector2f(x * current.width + 0.5f, y * current.height + 0.5f);
				quad[1].position = sf::Vector2f((x + 1) * current.width + 0.5f, (y * current.height) + 0.5f);
				quad[2].position = sf::Vector2f((x + 1) * current.width + 0.5f, (y + 1) * current.height + 0.5f);
				quad[3].position = sf::Vector2f((x * current.width) + 0.5f, (y + 1) * current.height + 0.5f);

				quad[0].texCoords = sf::Vector2f(current.x, current.y);
				quad[1].texCoords = sf::Vector2f(current.x + current.width, current.y);
				quad[2].texCoords = sf::Vector2f(current.x + current.width, current.y + current.height);
				quad[3].texCoords = sf::Vector2f(current.x, current.y + current.height);
			}
		}
	}

	
}

std::string Components::TileMap::dump(std::string name)
{
	return "-- Tile Map not implemented";
}

