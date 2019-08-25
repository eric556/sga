#pragma once
#include "StatefulElement.h"
#include <filesystem>

namespace Debug {
	class FilePicker : public StatefulElement {
	public:
		FilePicker();
		void Draw(Game & game) override;
		void Open(const std::string& filepath);
	public:
		std::string file;
		bool fileSelected;
	private:
		char filePathBuffer[2048];
		std::vector<std::filesystem::path> currentFiles;
		std::vector<std::filesystem::path> currentDirs;
		std::string currentPath;
	};
}