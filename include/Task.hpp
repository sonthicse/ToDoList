#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
private:
    bool completed;
    std::string title;
    std::string description;

public:
    Task(const std::string& title, const std::string& description);
    Task(const std::string& title, const std::string& description, const bool& completed);

    std::string getTitle() const;
    std::string getDescription() const;
    bool isCompleted() const;

    std::string info() const;

    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);
    void maskCompleted();
};

#include "../src/Task.cpp"

#endif