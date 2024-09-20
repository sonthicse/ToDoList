#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Task.hpp"
#include "FileHandler.hpp"
#include "config.hpp"
#include <vector>

class Database {
private:
    std::vector<Task> tasks;

public:
    Database();
    ~Database();

    std::vector<Task> getTask() const;

    void addTask(const Task& task);
    void deleteTask(const std::string& title);
};

#include "../src/Database.cpp"

#endif