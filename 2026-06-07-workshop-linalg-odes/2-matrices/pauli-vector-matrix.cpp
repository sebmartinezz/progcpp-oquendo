#include <vector>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>

void paulimatvec (const std::vector<double>&a, std::vector<std::complex<double>>&paulia);
void print_matrix(const std::vector<std::complex<double>> & data, int m, int n);

int main (int argc, char **argv){

    std::vector<double> v = {std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])};
    std::vector<std::complex<double>> pauliv (4, 0.0);

    paulimatvec(v, pauliv);
    print_matrix(pauliv, 2, 2);

    return 0; 
}


void paulimatvec (const std::vector<double>&a, std::vector<std::complex<double>>&paulia){
    assert(a.size()==3);

    paulia = {std::complex<double>(a[2], 0.0),
        std::complex<double>(a[0], -a[1]),
        std::complex<double>(a[0], a[1]),
        std::complex<double>(-a[2], 0.0)};
}
void print_matrix(const std::vector<std::complex<double>> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " "; //println no funciona con complex
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}