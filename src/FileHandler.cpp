#include "../include/FileHandler.hpp"

void FileHandler::loadData(const std::string& filePath, std::vector<Task>& data) {
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string title, description, completed;
            std::getline(ss, title, '|');
            std::getline(ss, description, '|');
            std::getline(ss, completed, '\n');

            data.push_back(Task(title, description, true ? completed == "1" : false));
        }
    } else {
        std::cerr << "Unable to open " << filePath << " for reading!\n";
    }
}

void FileHandler::saveData(const std::string& filePath, std::vector<Task>& data) {
    std::ofstream file(filePath);

    if (file.is_open()) {
        for (const Task& task : data) {
            file << task.getTitle() << "|" << task.getDescription() << "|" << task.isCompleted() << "\n";
        }
    } else {
        std::cerr << "Unable to open " << filePath << " for writing!\n";
    }
}