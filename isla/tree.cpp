#include <vector>
#include <stdexcept>

int initializeSequences(int r) {
    W.resize(r);
    X.resize(r);
    Y.resize(r);
    Z.resize(r);
}

std::vector<int> W;
std::vector<int> X;
std::vector<int> Y;
std::vector<int> Z;
int main() {
    int r = 0;
    
    if (r < 3) {
        throw std::runtime_error("r must be at least 3");
    } else if (r % 2 == 0) {
        throw std::runtime_error("r must be odd");
    }

    initializeSequences(r);

    return 0;
}