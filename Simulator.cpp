#include "Simulator.h"
#include <string>
#include <iostream>

Simulator::Simulator(Memory *mem, const std::vector<int> &accessSeq)
    : memory(mem), access_sequence(accessSeq), hits(0), misses(0), total_accesses(0) {}

void Simulator::runSimulation() {
    for (int address : access_sequence) {
        // For simplicity, assume all accesses result in a miss
        // Cache logic can be added later for detailed simulation
        misses++;
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