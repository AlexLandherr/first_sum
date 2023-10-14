#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::vector<std::string> txt_file_to_vector(std::string file_path);

    std::string first_n_digits_of_sum(std::vector<std::string> grid, int n);
}

#endif