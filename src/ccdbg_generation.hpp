// INCLUDE HEADERS AND NAMESPACES

#include <iostream>
#include <ggcat.hh>
#include <mutex>
#include <string.h>
#include "utils.hpp"

using namespace ggcat;


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


// VARIABLES SHOULD BE ALREADY SET TO THEIR DEFAULT VALUES
void generate_ccdbg(const std::string& fofPath, const std::string& outputFileName, const std::string& tempDir, const std::string& ColorNames, uint64_t threads, uint64_t kmerLength, uint64_t memory_gb) {

GGCATConfig config;

config.use_temp_dir = true;
config.temp_dir = tempDir,
config.memory = 2.0,
config.prefer_memory = true,
config.total_threads_count = threads,
config.intermediate_compression_level = -1,

config.use_stats_file = false;
config.stats_file = "";

GGCATInstance *instance = GGCATInstance::create(config);

std::vector<std::string> input_files {readFilePaths(fofPath)};
std::string graph_file {outputFileName};

std::vector<std::string> color_names {ColorNames};

size_t k {kmerLength};
size_t threads_count {threads};

std::string output_file = instance->build_graph_from_files(
    Slice<std::string>(input_files.data(), input_files.size()),
    graph_file,
    k,
    threads_count,
    false,
    1,
    ExtraElaborationStep_UnitigLinks,
    true,
    Slice<std::string>(color_names.data(), color_names.size()),
    -1);

// std::string input_query {input_files[0]};

// std::string output_query = instance->query_graph(
//     graph_file,
//     input_query,
//     "/tmp/query-results",
//     k,
//     threads_count,
//     false,
//     true,
//     ColoredQueryOutputFormat_JsonLinesWithNames);

// std::cout << "Output query file: " << output_query << std::endl;

// std::mutex print_kmer_lock;

// auto file_color_names =
//     GGCATInstance::dump_colors(GGCATInstance::get_colormap_file(graph_file));


}