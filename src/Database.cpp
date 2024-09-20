#include "../include/Database.hpp"

Database::Database() {
    FileHandler::loadData(tasksFilePath, tasks);
}

Database::~Database() {
    FileHandler::saveData(tasksFilePath, tasks);
}

std::vector<Task> Database::getTask() const { return tasks; }

void Database::addTask(const Task& task) {
    tasks.push_back(task);
}

void Database::deleteTask(const std::string& title) {
    for (auto task = tasks.begin(); task < tasks.end(); task++) {
        if (title == task->getTitle()) {
            tasks.erase(task);
            return;
        }
    }
}