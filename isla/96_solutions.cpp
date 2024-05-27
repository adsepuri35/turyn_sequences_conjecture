#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

void bruteForcing96Solutions() {
    //Create csv file
    std::ofstream file("96_solutions.csv");

    // Write header
    file << "w_1,w_r,x_1,x_r,y_1,y_r,z_1,z_r\n";

    int values[] = {-1, 1};
    for (int w_1 : values) {
        for (int w_r : values) {
            for (int x_1 : values) {
                for (int x_r : values) {
                    for (int y_1 : values) {
                        for (int y_r : values) {
                            for (int z_1 : values) {
                                for (int z_r : values) {
                                    if (w_1 * w_r + x_1 * x_r + y_1 * y_r + z_1 * z_r == 0) {
                                        file << w_1 << "," << w_r << "," << x_1 << "," << x_r << "," << y_1 << "," << y_r << "," << z_1 << "," << z_r << "\n";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    bruteForcing96Solutions();
    return 0;
}