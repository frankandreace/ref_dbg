// INCLUDE HEADERS AND NAMESPACES
#include <iostream>
#include "../external/sshash/dictionary.hpp"



/* TO DEFINE
> temp_dir
> memory
> threads
> input_fof
> output_graph_name
> reference_path
> color_names (optional)
> kmer length
*/ 

std::cerr << "[info] building k-mer dictionary"  << std::endl;

sshash::dictionary kmer_dict;
{
    // std::ofstream ofs("sshash.log", std::ios::out);
    // std::streambuf *coutbuf = std::cout.rdbuf();
    // if (ofs.good()) {
    //   std::cout.rdbuf(ofs.rdbuf());
    // }


    sshash::build_configuration build_config;
    build_config.k = ksize;
    build_config.m = msize;
    build_config.c = 5.0;
    build_config.pthash_threads = nb_threads;
    build_config.canonical_parsing = true;
    build_config.verbose = false;

    kmer_dict.build(utg_file, build_config);

    // std::cout.rdbuf(coutbuf);
}

std::cerr << "[info] unitigs processed: " << kmer_dict.num_contigs() << std::endl;
std::cerr << "[info] k-mers processed: " << kmer_dict.size() << std::endl;
