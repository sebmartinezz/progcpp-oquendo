#include <eigen3/Eigen/Dense>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cassert>

void hilbert_fill (Eigen::MatrixXd&H, int m, int n);
void eigen (Eigen::MatrixXd H);

int main(int argc, char **argv)
{
    int m = std::stoi(argv[1]);
    int n = std::stoi(argv[2]);

    Eigen::MatrixXd h (m, n);
    hilbert_fill(h, m, n);
    std::cout<<"la matriz H:\n"<<h<<std::endl;
    eigen(h);

    return 0;
}

void hilbert_fill (Eigen::MatrixXd&H, int m, int n)
{
    for (int ii = 0; ii < m; ii++){
        for (int jj = 0; jj< n; jj++){
            H(ii, jj)=1.0/((ii+1.0)+(jj+1.0)-1.0);
        }
    }

}

void eigen (Eigen::MatrixXd H)
{
    assert(H.rows()==H.cols());
    Eigen::EigenSolver<Eigen::MatrixXd> es (H);
    std::cout <<"el vector de valores propios de H:\n"<< es.eigenvalues() <<"\nla matriz de vectores propios de H: \n"<< es.eigenvectors()<<std::endl;
}