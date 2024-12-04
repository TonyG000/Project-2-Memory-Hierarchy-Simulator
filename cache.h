#ifndef CACHE_H
#define CACHE_H

#include "Cacheline.h"
#include <vector>
#include<string>
using namespace std;
class Cache {
private:
    int cacheSize;
    int lineSize;
    string data;
    int numLines;
    std::vector<Cacheline> lines;

public:
    Cache(int cacheSize, int lineSize);
    bool accessMemory(int address, const std::string &inputData);
    void displayCache() const;
};

#endif // CACHE_H
