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

  const double K  = std::atof(argv[1]); //ASCII to float
  const double M1 = std::atof(argv[2]);
  const double M2 = std::atof(argv[3]);
  std::cout << K << "\t" << M1 << "\t" << M2 << "\t";
  solvesystem(K, M1, M2);
  return 0;
}

// implement here the needed function


void solvesystem(double k, double m1, double m2)
{
  Eigen::MatrixXd A (2, 2);
  A << (2.0*k)/m1, -k/m1, -k/m2, 2.0*k/m2;

  Eigen::EigenSolver<Eigen::MatrixXd> es (A);
  std::cout << es.eigenvalues()[0].real() << "\t"<< es.eigenvalues()[1].real()<< "\n";
}
