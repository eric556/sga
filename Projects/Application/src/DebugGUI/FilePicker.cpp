#include "FilePicker.h"
#include "imgui.h"
#include "imgui-SFML.h"


Debug::FilePicker::FilePicker()
{
	fileSelected = false;
	file = "";
	filePathBuffer[0] = 0;
}

void Debug::FilePicker::Draw(Game & game)
{
	if (isVisible) {
		ImGui::OpenPopup("File Picker");
		ImGui::SetNextWindowSize(sf::Vector2f(600, 600));
	}

	if (ImGui::BeginPopupModal("File Picker")) {
		if (ImGui::InputText("File Path", filePathBuffer, 2048, ImGuiInputTextFlags_EnterReturnsTrue)) {
			std::string temp = std::string(filePathBuffer);
			if (std::filesystem::is_directory(temp)) {
				Open(temp);
			} else {
				fileSelected = true;
				ImGui::CloseCurrentPopup();
			}
		}

		ImGui::SameLine();

		if (ImGui::Button("Select")) {
			fileSelected = true;
			file = std::string(filePathBuffer);
			ImGui::CloseCurrentPopup();
		}

		if (ImGui::Button("..")) {
			std::filesystem::path temp(currentPath);
			currentPath = temp.parent_path().string();
			Open(currentPath);
		}

		for (const auto& path : currentDirs) {
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.5f, 0.6f, 0.6f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.5f, 0.7f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.5f, 0.8f, 0.8f));
			if (ImGui::Button(path.filename().string().c_str())) {
				Open(path.string());
			}
			ImGui::PopStyleColor(3);
		}
		for (const auto& path : currentFiles) {
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.1f, 0.6f, 0.6f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.1f, 0.7f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.1f, 0.8f, 0.8f));
			if (ImGui::Button(path.filename().string().c_str())) {
				Open(path.string());
			}
			ImGui::PopStyleColor(3);
		}

		ImGui::Separator();

		if (ImGui::Button("Cancel")) {
			ImGui::CloseCurrentPopup();
			isVisible = false;
			fileSelected = false;
			file = "";
			filePathBuffer[0] = 0;
		}
		ImGui::EndPopup();
	}
}

void Debug::FilePicker::Open(const std::string & filepath)
{
	if (std::filesystem::exists(filepath)) {
		currentPath = std::filesystem::absolute(filepath).string();
		if (std::filesystem::is_directory(currentPath)) {
			currentDirs.clear();
			currentFiles.clear();
			for (const auto& entry : std::filesystem::directory_iterator(currentPath))
			{
				auto filename = std::filesystem::absolute(entry.path());
				if (std::filesystem::is_directory(entry)) {
					currentDirs.push_back(filename);
				} else {
					currentFiles.push_back(filename);
				}
			}
		} else {
			strcpy(filePathBuffer, currentPath.c_str());
		}
	}
}
