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
    int numLines;
    int cacheAccessTime;
    vector<Cacheline> lines;

public:
    Cache(int cacheSize, int lineSize, int cacheAccessTime);
    bool accessMemory(int address, const string &inputData);
    void displayCache() const;
    float getcacheAccessTime();
};

#endif
