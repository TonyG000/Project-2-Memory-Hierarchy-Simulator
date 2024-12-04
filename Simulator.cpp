#include "simulator.h"
#include <string>
#include <iostream>
#include "cache.h"
#include <unordered_map>

Simulator::Simulator(Memory *mem, const std::vector<int> &accessSeq)
    : memory(mem), access_sequence(accessSeq), hits(0), misses(0), total_accesses(0) {}


void Simulator::runSimulation() {
    int cacheSize = 64;
    int lineSize = 16;
    Cache cache(cacheSize, lineSize);

    // Address to data mapping
    std::unordered_map<int, std::string> addressToData = {
        {1024, "cocacola"},
        {2048, "icecream"},
        {4096, "chips"},
        {8192, "water"}
    };

    for (int address : access_sequence) {
        std::string data = addressToData[address];
        std::cout << "Accessing memory at address: " << address << " with data: " << data << std::endl;

        if (cache.accessMemory(address, data)) {
            hits++;
        } else {
            misses++;
        }
        total_accesses++;
    }
}

float Simulator::calculateHitRatio() const {
    return total_accesses == 0 ? 0.0f : static_cast<float>(hits) / total_accesses;
}

float Simulator::calculateMissRatio() const {
    return total_accesses == 0 ? 0.0f : static_cast<float>(misses) / total_accesses;
}

void Simulator::generateReport(const std::string &filePath) const {
    std::string report;
    report += "Total Accesses: " + std::to_string(total_accesses) + "\n";
    report += "Hits: " + std::to_string(hits) + "\n";
    report += "Misses: " + std::to_string(misses) + "\n";
    report += "Hit Ratio: " + std::to_string(calculateHitRatio()) + "\n";
    report += "Miss Ratio: " + std::to_string(calculateMissRatio()) + "\n";

    FileManager::writeReport(filePath, report);
}