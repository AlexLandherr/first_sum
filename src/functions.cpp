#include "include/functions.h"
#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

namespace func {
    std::vector<std::string> txt_file_to_vector(std::string file_path) {
        std::vector<std::string> grid;
        std::fstream grid_file(file_path);
        std::string single_line;

        while (std::getline(grid_file, single_line)) {
            //Remove irrelevant chars from line.
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\n'), single_line.cend());
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\r'), single_line.cend());

            //Add single_line to grid vector.
            grid.push_back(single_line);
        }

        return grid;
    }

    std::string first_n_digits_of_sum(std::vector<std::string> grid, int n) {
        std::string result;
        int carry = 0;

        for (int col = (static_cast<int>(grid[0].size()) - 1); col >= 0; col--) {
            int col_sum = carry;

            for (int row = 0; row < static_cast<int>(grid.size()); row++) {
                col_sum += std::stoi(grid[row].substr(col, 1));
            }

            //Calculate place_value; the digit that takes the nth place in the result std::string.
            std::string place_value = std::to_string(col_sum % 10);
            result.insert(0, place_value);

            //Calculate the carry value for the next col_sum.
            carry = col_sum / 10;
        }

        //Prepend the final carry value to the result std::string.
        result.insert(0, std::to_string(carry));

        return result.substr(0, n);
    }
}