#include "matrix_utils.h"
#include <print>

int main ( int argc, char **argv){

    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);
    int p = std::stoi(argv[3]);

    std::vector<double> mat (m*n, 0.0);
    std::vector<double> matp (m*n, 0.0);
    fill_matrix(mat, m, n);
    matpow (mat, m, n, matp, m, n, p);
    
    print_matrix(matp, m, n);

    return 0;
}