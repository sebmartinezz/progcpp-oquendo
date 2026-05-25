#include <valarray>
#include <iostream>
#include <cmath>
#include <cassert>

void matmul (const std::valarray<double>&A, int mA, int nA,
            const std::valarray<double>&B, int mB, int nB,
            std::valarray<double>&C, int mC, int nC);

void print_matrix(const std::valarray<double> & data, int m, int n);

int main(int argc, char **argv)
{
    double vx = std::stod(argv[1]);
    double vy = std::stod(argv[2]);
    double vz = std::stod(argv[3]);

    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    std::valarray<double> v = {vx, vy, vz};
    std::valarray<double> Rx = {1.0, 0.0, 0.0, 0.0, std::cos(thetax), -std::sin(thetax), 0.0, std::sin(thetax), std::cos(thetax)};
    std::valarray<double> Ry = {std::cos(thetay), 0.0, std::sin(thetay), 0.0, 1.0, 0.0, -std::sin(thetay), 0.0, std::cos(thetay)};
    std::valarray<double> Rz = {std::cos(thetaz), -std::sin(thetaz), 0.0, std::sin(thetaz), std::cos(thetaz), 0.0, 0.0, 0.0, 1.0};

    std::valarray<double> Rxv (0.0, 3);
    matmul(Rx, 3, 3, v, 3, 1, Rxv, 3, 1);
    std::valarray<double> RyRxv(0.0, 3);
    matmul(Ry, 3, 3, Rxv, 3, 1, RyRxv, 3, 1);
    std::valarray<double> RzRyRxv(0.0, 3);
    matmul(Rz, 3, 3, RyRxv, 3, 1, RzRyRxv, 3, 1);

    print_matrix(RzRyRxv, 3, 1);
    return 0;
}

void matmul(const std::valarray<double>& A, int mA, int nA,
            const std::valarray<double>& B, int mB, int nB,
            std::valarray<double>& C, int mC, int nC)
{
    assert(nA == mB);
    assert(mC == mA);
    assert(nC == nB);

    for (int ii = 0; ii < mC; ii++) {
        std::valarray<double> rowA = A[std::slice(ii * nA, nA, 1)]; //fila de A

        for (int jj = 0; jj < nC; jj++)
        {
            std::valarray<double> colB = B[std::slice(jj, mB, nB)]; //columna de B
            C[ii * nC + jj] = (rowA * colB).sum(); //prod punto
        }
    }
}

void print_matrix(const std::valarray<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}