// Copyright (C) Olympus Corporation. All rights reserved.

#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "external/baidu_apollo/modules/map/proto/map.pb.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    std::string test_data_path =
        "external/baidu_apollo/modules/map/hdmap/test-data/base_map.bin";

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        // 在这里添加你的选项
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    // TODO: Read the map file and parse it.
    // 1. Read the map file.
    std::fstream input(test_data_path, std::ios::in | std::ios::binary);
    if (!input) {
        std::cerr << "Failed to open " << test_data_path << std::endl;
        return -1;
    }
    apollo::hdmap::Map map;
    if (!map.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse map." << std::endl;
        return -1;
    }
    // 2. Parse the map file.
    // 3. Output the parsed map file.
    std::cout<<"Finished!"<<std::endl;
    return 0;
}