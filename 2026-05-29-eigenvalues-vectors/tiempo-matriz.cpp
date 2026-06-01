#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <complex>
#include <chrono>

int main(int argc, char **argv) {

   for (int N=1; N<=150; N++){

    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N,N);

        auto start =std::chrono::high_resolution_clock::now(); //inicio chrono
    Eigen::EigenSolver<Eigen::MatrixXd> es(A);
   auto end = std::chrono::high_resolution_clock::now(); //fin chrono
    std::chrono::duration<double> duration = end - start;

    std::cout << N << "\t"<< duration.count()/0.453079 << "\t" << std::endl;
    std::complex<double> lambda = es.eigenvalues()[0];
    }
    return 0;
}