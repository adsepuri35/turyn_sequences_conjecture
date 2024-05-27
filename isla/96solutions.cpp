#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

void bruteForcing96Solutions() {
    int values[] = {-1, 1};
    for (int w1 : values) {
        for (int wr : values) {
            for (int x1 : values) {
                for (int xr : values) {
                    for (int y1 : values) {
                        for (int yr : values) {
                            for (int z1 : values) {
                                for (int zr : values) {
                                    if (w1 * wr + x1 * xr + y1 * yr + z1 * zr == 0) {
                                        // This combination satisfies the equation
                                        std::cout << w1 << " " << wr << " " << x1 << " " << xr << " " << y1 << " " << yr << " " << z1 << " " << zr << std::endl;
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