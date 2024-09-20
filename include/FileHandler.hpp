#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include "Task.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class FileHandler {
public:
    static void loadData(const std::string& filePath, std::vector<Task>& data);

    static void saveData(const std::string& filePath, std::vector<Task>& data);
};

#include "../src/FileHandler.cpp"

#endif