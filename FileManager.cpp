#include "FileManager.h"
#include <fstream>
#include <iostream>

std::vector<int> FileManager::readAccessSequence(const std::string &filePath) {
    std::vector<int> accessSequence;
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return accessSequence;
    }

    int address;
    while (file >> address) {
        accessSequence.push_back(address);
    }

    file.close();
    return accessSequence;
}
void FileManager::writeReport(const std::string &filePath, const std::string &report) {
    std::ofstream file(filePath, std::ios_base::app);

    if (!file) {
        std::cerr << "Error writing to file: " << filePath << std::endl;
        return;
    }

    file << report;
    file.close();
}