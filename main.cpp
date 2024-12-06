#include <iostream>
#include <vector>
#include "Memory.h"
#include "cache.h"
#include "FileManager.h"
#include "simulator.h"

int main() {
    // Step 1: Hardcoded Memory Information
    int addressBits = 20;       // Number of bits for addressing the memory
    int memoryAccessTime = 100; // Memory access time in cycles

    // Initialize Memory
    Memory memory(addressBits, memoryAccessTime);


    // Step 2: Hardcoded Cache Information
    int cacheSize = 4096;         // Cache size in bytes
    int cacheLineSize = 1024;     // Cache line size in bytes
    int cacheAccessTime = 5;    // Cache access time in cycles

    Cache cache(cacheSize, cacheLineSize, cacheAccessTime);

    // Validate hardcoded input
    if (cacheLineSize > cacheSize || cacheLineSize <= 0) {
        std::cerr << "Invalid cache configuration. Exiting.\n";
        return 1;
    }

    // Step 3: Read Access Sequence from File
    std::string filePath = "access_sequence.txt"; // File containing the sequence
    std::vector<int> accessSequence = FileManager::readAccessSequence(filePath);

    if (accessSequence.empty()) {
        std::cerr << "Failed to read access sequence or file is empty. Exiting.\n";
        return 1;
    }

    // Step 4: Initialize Simulator
    Simulator simulator(&memory, accessSequence, &cache);

    // Step5: Run Simulation
    simulator.runSimulation();

    // Step 6: Generate Report
    std::string reportFilePath = "D:\\C++\\Project-2-Memory-Hierarchy-Simulator\\simulation_report.txt";
    simulator.generateReport(reportFilePath);

    // Output completion message
    std::cout << "Simulation completed. Report saved to " << reportFilePath << std::endl;

    return 0;
}
