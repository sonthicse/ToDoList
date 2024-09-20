#include "../include/Task.hpp"

Task::Task(const std::string& title, const std::string& description)
    : title(title), description(description), completed(false) {}

Task::Task(const std::string& title, const std::string& description, const bool& completed)
    : title(title), description(description), completed(completed) {}

std::string Task::getTitle() const { return title; }

std::string Task::getDescription() const { return description; }

bool Task::isCompleted() const { return completed; }

std::string Task::info() const {
    std::string info;
    
    if (isCompleted()) {
        info += "[ ] ";
    } else {
        info += "[X] ";
    }

    info += "Title: " + getTitle() + ", Description: " + getDescription();

    return info;
}

void Task::setTitle(const std::string& newTitle) { title = newTitle; }

void Task::setDescription(const std::string& newDescription) { description = newDescription; }

void Task::maskCompleted() { completed = true; }