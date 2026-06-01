#include <eigen3/Eigen/Dense>
#include <iostream>
#include <complex>
#include <cstdlib>

void powmat (long k, Eigen::MatrixXd A, Eigen::MatrixXcd&powA);

int main (int argc, char **argv)
{
    long N = std::stol(argv[1]);
    long K = std::stol(argv[2]);
    std::srand(42);

    Eigen::MatrixXd S = Eigen::MatrixXd::Random(N, N);
    Eigen::MatrixXcd powS;

    powmat(K, S, powS);

    std::cout << "la matriz S es:\n"<< S <<"\n la matriz powS es:\n"<< powS<<std::endl;

    return 0;
}

void powmat (long k, Eigen::MatrixXd A, Eigen::MatrixXcd&powA)
{
    Eigen::EigenSolver<Eigen::MatrixXd> es (A); //autovalores y autovectores
    Eigen::MatrixXcd D = es.eigenvalues().asDiagonal();
    D = D.array().pow(k);

    powA = es.eigenvectors()*D*es.eigenvectors().inverse();
}