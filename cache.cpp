#include "Cache.h"
#include <iostream>
using namespace std;

Cache::Cache(int cacheSize, int lineSize, int cacheAccessTime) {
    this->cacheSize = cacheSize;
    this->lineSize = lineSize;
    this->numLines = cacheSize / lineSize;
    this->cacheAccessTime = cacheAccessTime;
    lines.resize(numLines);
}

bool Cache::accessMemory(int address, const std::string &inputData) {
    int index = (address / lineSize) % numLines;
    int tag = (address / lineSize) / numLines;

    cout << "Accessing address: " << address << endl;
    cout << "Index: " << index << ", Tag: " << tag << endl;

    if (lines[index].valid && lines[index].tag == tag) {
        // Cache hit
        cout << "Result: HIT" << endl;
        cout << "Data: " << lines[index].data << endl;
        return true;
    } else {
        // Cache miss
        cout << "Result: MISS" << endl;

        // Update the cache line with new tag and data
        lines[index].valid = true;
        lines[index].tag = tag;
        lines[index].data = inputData;

        displayCache();
        return false;
    }
}

void Cache::displayCache() const {
    cout << "Cache Content:" << endl;
    for (int i = 0; i < numLines; i++) {
        cout << "Line " << i << ": ";
        lines[i].display();
    }
}

float Cache::getcacheAccessTime() {
    return this->cacheAccessTime;
}
