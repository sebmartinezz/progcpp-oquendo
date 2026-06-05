#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <complex>

void solvesystem(double k, double m1, double m2);

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "ERROR.\nUsage:\n" << argv[0] << " K M1 M2\n";
    return 1;
  }
  const double K  = std::atof(argv[1]);
  const double M1 = std::atof(argv[2]);
  const double M2 = std::atof(argv[3]);
  std::cout << K << "\t" << M1 << "\t" << M2 << "\t";
  solvesystem(K, M1, M2);
  return 0;
}

void solvesystem(double k, double m1, double m2)
{
  Eigen::Matrix2d A;
  A(0,0) = 2*k/m1;  A(0,1) = -k/m1;
  A(1,0) = -k/m2;   A(1,1) = 2*k/m2;

  Eigen::EigenSolver<Eigen::Matrix2d> es(A);
  double e1 = es.eigenvalues()[0].real();
  double e2 = es.eigenvalues()[1].real();
  if (e1 < e2) std::swap(e1, e2);
  std::cout << e1 << "\t" << e2 << "\n";
}