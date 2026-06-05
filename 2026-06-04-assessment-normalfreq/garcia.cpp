#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <complex>
#include <cmath>

void solvesystem(double k, double m1, double m2);

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "ERROR.\nUsage:\n" << argv[0] << " K M1 M2\n";
    return 1;
  }

  const double K  = std::atof(argv[1]);
  const double M1 = std::atof(argv[2]);
  const double M2 = std::atof(argv[3]);
  std::cout << K << "\t" << M1 << "\t" << M2 << std::endl;
  solvesystem(K, M1, M2);
  return 0;
}



void solvesystem(double k, double m1, double m2)
{
    Eigen::Matrix2d A;

    A << (2*k)/m1,  -(k/m1),
         -(k/m2),  (2*k)/m2;

    Eigen::EigenSolver<Eigen::Matrix2d> es(A);

    double lambda1 = es.eigenvalues()[0].real();
    double lambda2 = es.eigenvalues()[1].real();

      if(lambda1 > lambda2){
        std::swap(lambda1, lambda2);
      }

    double omega1 = std::sqrt(lambda1);
    double omega2 = std::sqrt(lambda2);

    std::cout << "Valores propios:" << "\t" << "λ1 = " << lambda1 << "\t" << "λ2 = " << lambda2 << std::endl;
    std::cout << "Frecuencias normales:" << "\t" << "ω1 = " << omega1 << " rad/s" << "\t" << "ω2 = " << omega2 << " rad/s" << std::endl;
} 