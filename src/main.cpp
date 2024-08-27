#include <iostream>
#include "utils.hpp"
#include "ccdbg_generation.hpp"
#include "dictionary_generation.hpp"

int main(int argc, char* argv[]) {

    // parse input options 

    std::string fofPath {""};
    std::string outputFileName {""};
    std::string tempDir {"/tmp"};
    std::string colorNames {""};
    uint64_t threads {8};
    uint64_t kmerLength {31};
    uint64_t memoryGb {2};
    int option;

    while ((option = getopt(argc, argv, "i:o:t:c:T:k:m:")) != -1) {
        switch (option) {
            case 'i':
                fofPath = optarg;
                break;
            case 'o':
                outputFileName = optarg;
                break;
            case 'temp':
                tempDir = optarg;
                break;
            case 'color':
                colorNames = optarg;
                break;
            case 'threads':
                threads = std::stoull(optarg);
                break;
            case 'k':
                kmerLength = std::stoull(optarg);
                break;
            case 'm':
                memoryGb = std::stoull(optarg);
                break;
            case '?': // Option not recognized
                return 1;
            default:
                abort();
        }
    }
    // CHECK THAT INPUT AND OUTPUT ARE SET
    if ((fofPath.size() == 0) || (outputFileName.size() == 0)){
        std::cerr << "[ERROR] CHECK INPUT FILE (-i) AND OUTPUT FILE (-o) WERE CORRECTLY PROVIDED!"  << std::endl;
        std::cerr << "[ERROR] provided INPUT FILE " << fofPath << std::endl;
        std::cerr << "[ERROR] provided OUTPUT FILE " << outputFileName << std::endl;
    }

    // build ccdbg using ggcat apis
    generate_ccdbg(fofPath, outputFileName, tempDir, colorNames, threads, kmerLength, memoryGb);

    // build sshash-based dictionary of k-mers
    
    
    return 0;
}