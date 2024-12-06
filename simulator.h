#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Memory.h"
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

public:
    Simulator(Memory *mem, const std::vector<int> &accessSeq);
    void runSimulation();
    float calculateHitRatio() const;
    float calculateMissRatio() const;
    void generateReport(const std::string &filePath) const;
};

#endif // SIMULATOR_H