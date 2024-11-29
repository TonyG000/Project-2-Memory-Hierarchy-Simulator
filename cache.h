#ifndef CACHE_H
#define CACHE_H
#include "Cacheline.h"  
#include <vector>      
using namespace std;
class Cache {
private:
    int cacheSize;        // Total cache size (S) in bytes
    int lineSize;         // Cache line size (L) in bytes
    int numLines;         // Number of cache lines
    vector<Cacheline> lines; // Vector of cache lines

public:
    Cache(int cacheSize, int lineSize);

    
    void accessMemory(int address);// Simulate accessing a memory address

    void displayCache() const;
};

#endif 
