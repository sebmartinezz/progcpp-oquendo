
#include<eigen3/Eigen/Dense>
#include <cmath>
#include <print>

int main (int argc, char **argv){

    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(2, 2);

    for (double n = 1.0; n<=3.0; n+=0.01){
    auto lensmat = [n](Eigen::MatrixXd&A){
        double R1 = 1.234;
        double R2 = 2.987;
        double d = 5.678;

        Eigen::MatrixXd A1 (2, 2);
        Eigen::MatrixXd A2 (2, 2);
        Eigen::MatrixXd A3 (2, 2);

        A1<<1, (n-1)/R2, 0, 1;
        A2<<1, 0, d/n, 1;
        A3<<1, (1-n)/R1, 0, 1;

        A=A1*A2*A3;
        double oof = -A(1, 0);
        double det = A.determinant();
        std::println("{:25.16e} {:25.16e} {:25.16e}", n, oof, det);
    };
    lensmat(A);
    }

    return 0;
}
