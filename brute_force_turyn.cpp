#include <iostream>
#include <vector>

// Function to implement the brute force turyn sequence algorithm
void bruteForceSequence(int r) {
    std::vector<int> W(r);
    std::vector<int> X(r);
    std::vector<int> Y(r);
    std::vector<int> Z(r);
}

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

int main() {
    int r = 3; // odd length

    std::vector<int> X = {-1, -1, -1};
    std::cout << NPAF(X, 1) << std::endl;
    std::cout << NPAF(X, 2) << std::endl;

    return 0;
}