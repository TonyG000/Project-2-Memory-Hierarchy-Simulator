#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Memory.h"
#include "cache.h"
#include "FileManager.h"
#include <vector>
#include <string>

class Simulator {
private:
    Memory *memory;
    std::vector<int> access_sequence;
    int hits;
    int misses;
    int total_accesses;
    Cache *cache;

public:
    Simulator(Memory *mem, const std::vector<int> &accessSeq, Cache *cache);
    void runSimulation();
    float calculateHitRatio() const;
    float calculateMissRatio() const;
    float calculateAMAT() const;
    void generateReport(const std::string &filePath) const;
};

#endif // SIMULATOR_H