#include "Cache.h"  
#include <iostream>   
using namespace std;
Cache::Cache(int cacheSize, int lineSize) {
    this->cacheSize = cacheSize;
    this->lineSize = lineSize;
    this->numLines = cacheSize / lineSize;

    lines.resize(numLines);
}

void Cache::accessMemory(int address) {
    // Calculate the index and tag from the memory address
    int index = (address / lineSize) % numLines;
    int tag = (address / lineSize) / numLines;

    cout << "Accessing address: " << address << endl;
    cout << "Index: " << index << ", Tag: " << tag << endl;

    // Check if the cache line at the index is valid and if the tag matches
    if (lines[index].valid && lines[index].tag == tag) {
        // Cache hit
        cout << "Result: HIT" << endl;
    } else {
        // Cache miss
        cout << "Result: MISS" << endl;

        // Update the cache line
        lines[index].valid = true;
        lines[index].tag = tag;
    }
}

void Cache::displayCache() const {
    cout << "Cache Content:" << endl;
    for (int i = 0; i < numLines; i++) {
        cout << "Line " << i << ": ";
        lines[i].display(); 
    }
}
