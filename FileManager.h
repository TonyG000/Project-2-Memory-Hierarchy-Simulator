#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

class FileManager {
public:
    static std::vector<int> readAccessSequence(const std::string &filePath);
    static void writeReport(const std::string &filePath, const std::string &report);
};

#endif // FILEMANAGER_H