#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <complex>
#include <chrono>

int main(int argc, char **argv) {

    // read the matrix ncols, to be NxN
    const int N = std::stoi(argv[1]);

    // create a random matrix
    // seed controlled by srand
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N,N);
    std::cout << "Here is a random matrix, A:" << std::endl 
            << A << std::endl << std::endl;

    // create an eigen solver with that matrix. 
    // Once created it solves everything inmediatly
        auto start =std::chrono::high_resolution_clock::now(); //inicio chrono
    Eigen::EigenSolver<Eigen::MatrixXd> es(A);
   auto end = std::chrono::high_resolution_clock::now(); //fin chrono
    std::chrono::duration<double> duration = end - start;

    std::cout << "The duration is: " << duration << std::endl;
    // print some results
    std::cout << "The eigenvalues of A are:" << std::endl 
            << es.eigenvalues() << std::endl;
    std::cout << "The matrix of eigenvectors, V, is:" << std::endl 
            << es.eigenvectors() << std::endl << std::endl;

    // Check the first eigen value: Av = lambda v
    std::complex<double> lambda = es.eigenvalues()[0];
    std::cout << "Consider the first eigenvalue, lambda = " << lambda << std::endl;
          std::cout << "The duration is: " << duration << std::endl;
    Eigen::VectorXcd v = es.eigenvectors().col(0);
    std::cout << "If v is the corresponding eigenvector, then lambda * v = " << std::endl 
            << lambda * v << std::endl;
    std::cout << "... and A * v = " << std::endl 
            << A.cast<std::complex<double> >() * v << std::endl << std::endl;

    // diagnalization check
    Eigen::MatrixXcd D = es.eigenvalues().asDiagonal();
    Eigen::MatrixXcd V = es.eigenvectors();
    std::cout << "Finally, V * D * V^(-1) = " << std::endl 
           << V * D * V.inverse() << std::endl;
    
    return 0;
}