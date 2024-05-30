#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

std::vector<int> W;
std::vector<int> X;
std::vector<int> Y;
std::vector<int> Z;


void generateEquations(int r) {
    std::string seq[] = {"w", "x", "y", "z"};
    for (int s = 1; s < r; s++) {
        std::string equation = "Equation " + std::to_string(s) + " = ";
        std::string lastTerm;

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < r; j++) {
                if (j + s > r) {
                    break;
                }
                if (!lastTerm.empty()) {
                    equation += lastTerm + " + ";
                }
                lastTerm = seq[i] + "_" + std::to_string(j) + " * " + seq[i] + "_" + std::to_string(j + s);
            }
        }
        equation += lastTerm;
        std::cout << equation << std::endl;
    }
}

int initializeSequences(int r) {
    W.resize(r);
    X.resize(r);
    Y.resize(r);
    Z.resize(r);
}


int main() {
    int r = 5;
    
    if (r < 3) {
        throw std::runtime_error("r must be at least 3");
    } else if (r % 2 == 0) {
        throw std::runtime_error("r must be odd");
    }

    initializeSequences(r);

    generateEquations(r);

    return 0;
}