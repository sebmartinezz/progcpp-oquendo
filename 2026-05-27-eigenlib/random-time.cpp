# include <iostream>
# include <eigen3/Eigen/Dense>
#include <string>
#include <cstdlib>
#include <chrono>

int main(int argc, char **argv)
{
    std::srand(42); //seed
    int N = std::stoi(argv[1]);
   Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N); //numeros aleatorios, tamaño de la matriz
   Eigen::VectorXd b = Eigen::VectorXd::Random(N);
   //std::cout.precision(16);
   //std::cout.setf(std::ios::scientific);
   
   //A << 1,2,3,  4,5,6,  7,8,10;
   //b << 3, 3, 4;
   std::cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector b:\n" << b << std::endl;

    auto start =std::chrono::high_resolution_clock::now(); //inicio chrono
   Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
   auto end = std::chrono::high_resolution_clock::now(); //fin chrono
    std::chrono::duration<double> duration = end - start;

   std::cout << "The solution is:\n" << x << std::endl;
      std::cout << "The duration is: " << duration << std::endl;
   std::cout << (A*x - b).norm() << "\n";
   return 0;
}