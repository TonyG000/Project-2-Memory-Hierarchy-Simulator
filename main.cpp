#include <iostream>
#include <vector>
#include "Memory.h"
#include "cache.h"
#include "FileManager.h"
#include "simulator.h"

int main() {
    // Step 1: Hardcoded Memory Information
    int addressBits = 32;       // Number of bits for addressing the memory
    int memoryAccessTime = 100; // Memory access time in cycles

    // Initialize Memory
    Memory memory1(addressBits, memoryAccessTime);
    Memory memory2(addressBits, memoryAccessTime);


    // Step 2: Hardcoded Cache Information
    int cacheSize = 256;         // Cache size in bytes
    int cacheLineSize = 16;     // Cache line size in bytes
    int cacheAccessTime = 1;    // Cache access time in cycles

    Cache cache1(cacheSize, cacheLineSize, cacheAccessTime);
    Cache cache2(cacheSize, cacheLineSize, cacheAccessTime);

    // Validate hardcoded input
    if (cacheLineSize > cacheSize || cacheLineSize <= 0) {
        std::cerr << "Invalid cache configuration. Exiting.\n";
        return 1;
    }

    // Step 3: Read Access Sequence from File
    std::string dataFilePath = "D:\\C++\\Project-2-Memory-Hierarchy-Simulator\\data.txt";
    std::string instrFilePath = "D:\\C++\\Project-2-Memory-Hierarchy-Simulator\\ins.txt";

    std::vector<int> dataAccessSequence = FileManager::readAccessSequence(dataFilePath);
    std::vector<int> instructionAccessSequence = FileManager::readAccessSequence(instrFilePath);


       if (instructionAccessSequence.empty() || dataAccessSequence.empty()) {
        std::cerr << "Failed to read access sequences or files are empty. Exiting.\n";
        return 1;
    }

    // Step 4: Initialize Simulator
    Simulator simulator1(&memory1, dataAccessSequence , &cache1);
    Simulator simulator2(&memory2, instructionAccessSequence, &cache2);


    // Step5: Run Simulation
    simulator1.runSimulation();
    simulator2.runSimulation();

    // Step 6: Generate Report
    std::string reportFilePath = "D:\\C++\\Project-2-Memory-Hierarchy-Simulator\\simulation_report.txt";
    simulator1.generateReportdata(reportFilePath);
    simulator2.generateReportinstructions(reportFilePath);

    // Output completion message
    std::cout << "Simulation completed. Report saved to " << reportFilePath << std::endl;

    return 0;
}
