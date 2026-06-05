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
    Eigen::Matrix2d M; //Declaramos la matriz, para este caso de 2x2
    M << (2*k)/m1,    -k/m1,
         -k/m2,       (2*k)/m2;

    Eigen::EigenSolver<Eigen::Matrix2d> es(M); //Inicializamos EigenSolver

    std::cout << es.eigenvalues()[0].real() << "\t" //Imprimimos la parte real de ambos valores propios
            << es.eigenvalues()[1].real() << "\n";
  
}