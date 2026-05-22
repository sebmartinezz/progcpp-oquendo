#include "matrix_utils.h"
#include <print>

int main ( int argc, char **argv){

    int m = std::stol(argv[1]);
    int n = std::stol(argv[2]);

    std::vector<double> matriz (m*n, 0.0);
    fill_matrix(matriz, m, n); //la llena con enteros en orden
    print_matrix(matriz, m, n);
    double traza = trace(matriz, m, n);
    std::println("{}", traza);

    return 0;
}