#include "include/functions.h"
#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <algorithm>

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

namespace func {
    std::vector<std::string> txt_file_to_vector(std::string file_path) {
        std::vector<std::string> grid;
        std::fstream grid_file(file_path);
        std::string single_line;

        while (std::getline(grid_file, single_line)) {
            //Remove irrelevant chars from line.
            //single_line.erase(std::remove(single_line.begin(), single_line.end(), ' '), single_line.cend());
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\n'), single_line.cend());
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\r'), single_line.cend());

            //Add grid_line to grid vector.
            grid.push_back(single_line);
        }

        return grid;
    }
}