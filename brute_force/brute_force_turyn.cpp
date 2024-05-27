#include <iostream>
#include <vector>

// Implementation of Non-periodic autocorrelation function(NPAF) with sequence X and shift s
int NPAF(std::vector<int>& X, int s) {
    int sum = 0;
    for (int i = 0; i < X.size(); i++) {
        if (i + s >= X.size()) {
            break;
        }
        sum += X[i] * X[(i + s)];
    }
    return sum;
}

// check if 4 sequences are turyn sequences
bool verifySequences(std::vector<int>& W, std::vector<int>& X,std::vector<int>& Y, std::vector<int>& Z, int r) {
    if (W.size() != r || X.size() != r || Y.size() != r || Z.size() != r) {
        throw std::invalid_argument("One of the sequences does not have a length equal to r");
    }

    std::vector<int> W_NPAF;
    std::vector<int> X_NPAF;
    std::vector<int> Y_NPAF;
    std::vector<int> Z_NPAF;

    for (int i = 1; i < r; i++) {
        W_NPAF.push_back(NPAF(W, i));
        X_NPAF.push_back(NPAF(X, i));
        Y_NPAF.push_back(NPAF(Y, i));
        Z_NPAF.push_back(NPAF(Z, i));
    }

    for (int i = 0; i < r - 1; i++) {
        if (W_NPAF[i] + X_NPAF[i] + Y_NPAF[i] + Z_NPAF[i] != 0) {
            return false;
        }
    }

    // std::cout << "NPAF-Applied Arrays:\n";
    // std::cout << "W_NPAF: ";
    // for (int w : W_NPAF) std::cout << w << " ";
    // std::cout << "\nX_NPAF: ";
    // for (int x : X_NPAF) std::cout << x << " ";
    // std::cout << "\nY_NPAF: ";
    // for (int y : Y_NPAF) std::cout << y << " ";
    // std::cout << "\nZ_NPAF: ";
    // for (int z : Z_NPAF) std::cout << z << " ";
    // std::cout << "\n";

    return true;
}

// Function to implement the brute force turyn sequence algorithm
int bruteForceTurynSequences(int r) {
    int numSequences = 0;

    std::vector<int> W(r);
    std::vector<int> X(r);
    std::vector<int> Y(r);
    std::vector<int> Z(r);

    for (int i = 0; i < (1 << r); ++i) {
        for (int j = 0; j < r; ++j) {
            W[j] = (i & (1 << j)) ? 1 : -1;
        }
        for (int i = 0; i < (1 << r); ++i) {
            for (int j = 0; j < r; ++j) {
                X[j] = (i & (1 << j)) ? 1 : -1;
            }
            for (int i = 0; i < (1 << r); ++i) {
                for (int j = 0; j < r; ++j) {
                    Y[j] = (i & (1 << j)) ? 1 : -1;
                }
                for (int i = 0; i < (1 << r); ++i) {
                    for (int j = 0; j < r; ++j) {
                        Z[j] = (i & (1 << j)) ? 1 : -1;
                    }
                    if (verifySequences(W, X, Y, Z, r)) {
                        // std::cout << "W: ";
                        // for (int w : W) std::cout << w << " ";
                        // std::cout << "\nX: ";
                        // for (int x : X) std::cout << x << " ";
                        // std::cout << "\nY: ";
                        // for (int y : Y) std::cout << y << " ";
                        // std::cout << "\nZ: ";
                        // for (int z : Z) std::cout << z << " ";
                        // std::cout << "\n";
                        numSequences++;
                    }
                }
            }
        }
    }
    return numSequences;
}

int main() {
    int r = 5; // odd length

    std::cout << bruteForceTurynSequences(r) << std::endl;

    // Verifying sequences with r = 7
    // std::vector<int> W = {1, 1, -1, -1, -1, -1, -1};
    // std::vector<int> X = {1, -1, 1, 1, -1, 1, 1};
    // std::vector<int> Y = {1, 1, 1, -1, -1, 1, 1};
    // std::vector<int> Z = {1, -1, 1, -1, 1, -1, -1};
    // verifySequences(W, X, Y, Z, 7);

    return 0;
}