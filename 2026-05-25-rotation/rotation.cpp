#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC);

void print_matrix(const std::vector<double> & data, int m, int n);

int main(int argc, char **argv)
{
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);

    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    std::vector<double> v = {vx, vy, vz};
    std::vector<double> Rx = {1.0, 0.0, 0.0, 0.0, std::cos(thetax), -std::sin(thetax), 0.0, std::sin(thetax), std::cos(thetax)};
    std::vector<double> Ry = {std::cos(thetay), 0.0, std::sin(thetay), 0.0, 1.0, 0.0, -std::sin(thetay), 0.0, std::cos(thetay)};
    std::vector<double> Rz = {std::cos(thetaz), -std::sin(thetaz), 0.0, std::sin(thetaz), std::cos(thetaz), 0.0, 0.0, 0.0, 1.0};

    std::vector<double> Rxv (3, 0.0);
    matmul(Rx, 3, 3, v, 3, 1, Rxv, 3, 1);
    std::vector<double> RyRxv(3, 0.0);
    matmul(Ry, 3, 3, Rxv, 3, 1, RyRxv, 3, 1);
    std::vector<double> RzRyRxv(3, 0.0);
    matmul(Rz, 3, 3, RyRxv, 3, 1, RzRyRxv, 3, 1);

    print_matrix(RzRyRxv, 3, 1);
    return 0;
}

void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC)
{
  assert(nA==mB);
  assert(mC==mA);
  assert(nC==nB);

  for (int ii = 0; ii<mC; ii++) //filas
  {
    for (int jj=0; jj<nC; jj++) //columnas
    {
      C[ii*nC+jj]=0.0;
      for (int kk=0; kk<nA; ++kk)
      {
        C[ii*nC+jj]+= A[ii*nA + kk]*B[kk*nB + jj];
      }

    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}