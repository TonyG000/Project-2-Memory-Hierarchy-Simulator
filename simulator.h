#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Memory.h"
#include "cache.h"
#include "FileManager.h"
#include <vector>
#include <string>

class Simulator {
private:
    Memory *memory;                                 // Pointer to memory object
    std::vector<int> instruction_access_sequence;   // Sequence of instruction memory accesses
    std::vector<int> data_access_sequence;          // Sequence of data memory accesses
    Cache *instrCache;                              // Pointer to instruction cache
    Cache *dataCache;                               // Pointer to data cache

    int hits;                                       // Total cache hits
    int misses;                                     // Total cache misses
    int total_accesses;                             // Total memory accesses (instructions + data)

public:
    // Constructor
    Simulator(Memory *mem, const std::vector<int> &instrSeq, const std::vector<int> &dataSeq, 
              Cache *instrCache, Cache *dataCache);

    // Run the simulation for both instruction and data sequences
    void runSimulation();

    // Calculate the hit ratio
    float calculateHitRatio() const;

    // Calculate the miss ratio
    float calculateMissRatio() const;

    // Calculate the average memory access time (AMAT)
    float calculateAMAT() const;

    // Generate a report of the simulation results
    void generateReport(const std::string &filePath) const;
};

#endif // SIMULATOR_H
