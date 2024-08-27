#include <iostream>
#include 
#include <fstream>
#include <vector>
#include <string>
#include <cstdint> // For uint64_t
#include <unistd.h> // For getopt


// read file paths from the specified file and return them in a vector
std::vector<std::string> readFilePaths(const std::string& fofPath) {
    std::vector<std::string> files;
    std::ifstream inFile(fofPath);
    std::string line;
    
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file: " << fofPath << std::endl;
        return files; // Return an empty vector if the file cannot be opened
    }
    
    while (getline(inFile, line)) {
        if (!line.empty()) {
            files.push_back(line); // Add the path to the vector
        }
    }
    
    inFile.close();
    return files;
}