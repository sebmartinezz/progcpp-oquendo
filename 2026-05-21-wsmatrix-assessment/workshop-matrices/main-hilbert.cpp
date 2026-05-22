#include "matrix_utils.h"
#include <print>

int main ( int argc, char **argv){

    int m = std::stol(argv[1]);
    int n = std::stol(argv[2]);

    std::vector<double> hilbert (m*n, 0.0);
    hilbert_fill(hilbert, m, n); //la llena como una matriz de hilbert
    print_matrix(hilbert, m, n);
    double traceh = trace(hilbert, m, n);
    std::println("{}", traceh);

    

    return 0;
}