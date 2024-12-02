#include "Memory.h"
#include "Simulator.h"
#include "FileManager.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Initialize Memory
    Memory memory(16, 10); // 16 address bits, 10 cycles access time

    // Read access sequence from file
    std::string inputFilePath = "access_sequence.txt";
    std::vector<int> accessSequence = FileManager::readAccessSequence(inputFilePath);

    // Initialize Simulator
    Simulator simulator(&memory, accessSequence);

    // Run Simulation
    simulator.runSimulation();

    // Generate Report
    std::string reportFilePath = "simulation_report.txt";
    simulator.generateReport(reportFilePath);

    std::cout << "Simulation completed. Report saved to " << reportFilePath << std::endl;

    return 0;
}