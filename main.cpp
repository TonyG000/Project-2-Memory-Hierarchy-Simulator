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


    int cacheSize = 4096;         // Cache size in bytes
    int cacheLineSize = 1024;     // Cache line size in bytes
    int cacheAccessTime = 5;      // Cache access time in cycles

    // Initialize two caches: instruction and data
    Cache instructionCache(cacheSize, cacheLineSize, cacheAccessTime);
    Cache dataCache(cacheSize, cacheLineSize, cacheAccessTime);

    // Validate hardcoded input
    if (cacheLineSize > cacheSize || cacheLineSize <= 0) {
        std::cerr << "Invalid cache configuration. Exiting.\n";
        return 1;
    }

    // Step 3: Read Access Sequence from File
    std::string instrFilePath = "C:/Users/dell/Documents/GitHub/Project-2-Memory-Hierarchy-Simulator/cmake-build-debug/instruction_sequence.txt";
    std::string dataFilePath = "C:/Users/dell/Documents/GitHub/Project-2-Memory-Hierarchy-Simulator/cmake-build-debug/data_sequence.txt";

    std::vector<int> instructionAccessSequence = FileManager::readAccessSequence(instrFilePath);
    std::vector<int> dataAccessSequence = FileManager::readAccessSequence(dataFilePath);

    if (instructionAccessSequence.empty() || dataAccessSequence.empty()) {
        std::cerr << "Failed to read access sequences or files are empty. Exiting.\n";
        return 1;
    }

  if (instructionAccessSequence.empty() || dataAccessSequence.empty()) {
    std::cerr << "Failed to read access sequences or files are empty. Exiting.\n";
    return 1;
  }
    // Step 4: Initialize Simulator
    Simulator simulator(&memory, instructionAccessSequence, dataAccessSequence, &instructionCache, &dataCache);

    // Step5: Run Simulation
    simulator.runSimulation();

    // Step 6: Generate Report
    std::string reportFilePath = "C:/Users/dell/Documents/GitHub/Project-2-Memory-Hierarchy-Simulator/cmake-build-debug/simulation_report.txt";
    simulator.generateReport(reportFilePath);

    // Output completion message
    std::cout << "Simulation completed. Report saved to " << reportFilePath << std::endl;

    return 0;
}