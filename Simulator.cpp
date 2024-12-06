#include "Simulator.h"
#include <iostream>

Simulator::Simulator(
    Memory *mem,
    const std::vector<int> &instructionSeq,
    const std::vector<int> &dataSeq,
    Cache *instrCache,
    Cache *dataCache
)
    : memory(mem),
      instruction_access_sequence(instructionSeq),
      data_access_sequence(dataSeq),
      instrCache(instrCache),
      dataCache(dataCache),
      hits(0),
      misses(0),
      total_accesses(0) {}

void Simulator::runSimulation() {
    // Process instruction accesses
std::cout << "Processing Instruction Memory Accesses:\n";
for (size_t i = 0; i < instruction_access_sequence.size(); i++) {
    int address = instruction_access_sequence[i];
    std::string data = "InstrData_" + std::to_string(address);

    if (instrCache->accessMemory(address, data)) {
        hits++;
    } else {
        misses++;
    }
    total_accesses++;
}

// Process data accesses
std::cout << "Processing Data Memory Accesses:\n";
for (size_t i = 0; i < data_access_sequence.size(); i++) {
    int address = data_access_sequence[i];
    std::string data = "Data_" + std::to_string(address);

    if (dataCache->accessMemory(address, data)) {
        hits++;
    } else {
        misses++;
    }
    total_accesses++;
}

    std::cout << "Simulation complete.\n";
    std::cout << "Total Hits: " << hits << "\n";
    std::cout << "Total Misses: " << misses << "\n";
    std::cout << "Total Accesses: " << total_accesses << "\n";
}

float Simulator::calculateHitRatio() const {
    if (total_accesses == 0) {
        return 0.0;
    }
    return static_cast<float>(hits) / total_accesses;
}

float Simulator::calculateMissRatio() const {
    if (total_accesses == 0) {
        return 0.0;
    }
    return static_cast<float>(misses) / total_accesses;
}

float Simulator::calculateAMAT() const {
    // Separate AMAT for instructions and data
    float instructionAMAT = instrCache->getcacheAccessTime() +
                            calculateMissRatio() * memory->getAccessTime();
    float dataAMAT = dataCache->getcacheAccessTime() +
                     calculateMissRatio() * memory->getAccessTime();
    return (instructionAMAT + dataAMAT) / 2; // Average of both
}

void Simulator::generateReport(const std::string &filePath) const {
    std::string report;
    report += "Simulation Report\n\n";
    report += "Instruction Cache Results:\n";
    report += "Total Instruction Accesses: " + std::to_string(instruction_access_sequence.size()) + "\n";
    report += "Hits: " + std::to_string(hits) + "\n";
    report += "Misses: " + std::to_string(misses) + "\n";
    report += "Hit Ratio: " + std::to_string(calculateHitRatio()) + "\n\n";

    report += "Data Cache Results:\n";
    report += "Total Data Accesses: " + std::to_string(data_access_sequence.size()) + "\n";
    report += "Hits: " + std::to_string(hits) + "\n";
    report += "Misses: " + std::to_string(misses) + "\n";
    report += "Hit Ratio: " + std::to_string(calculateHitRatio()) + "\n\n";

    report += "Overall Accesses:\n";
    report += "AMAT: " + std::to_string(calculateAMAT()) + "\n";

    FileManager::writeReport(filePath, report);
}

