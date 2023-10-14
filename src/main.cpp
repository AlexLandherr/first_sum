#include "include/functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

int main() {
    auto vec = func::txt_file_to_vector("prob13.txt");
    for (std::string row : vec) {
        std::cout << row << '\n';
    }

    return 0;
}