//electrostatic potential on a planar region

#include<eigen3/Eigen/Dense>
#include <cmath>
#include <iostream>

int index (int ii, int jj, int N){
    return ii*N+jj;
}
void system (Eigen::MatrixXd&A, Eigen::VectorXd&b, int N, double L);

int main (int argc, char **argv){

    int N = 10;
    double L = 1.0;
    int totalpoints = N*N;

    Eigen::MatrixXd A= Eigen::MatrixXd::Zero (totalpoints, totalpoints);
    Eigen::VectorXd b = Eigen::VectorXd::Zero(totalpoints);

    system(A, b, N, L);
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    std::cout<<x<<"\n";
    return 0;
}

void system (Eigen::MatrixXd&A, Eigen::VectorXd&b, int N, double L)
{
    double h = L / (N - 1); //paso en la rejilla

    for (int ii = 0; ii < N; ++ii) {
        double x = ii * h; //posicion en el espacio
        for (int jj = 0; jj < N; jj++) {
            
            int k = index(ii, jj, N);

            //puntos frontera
            // abajo
            if (jj == 0) {
                A(k, k) = 1.0;
                b(k) = 5.0 * std::sin(M_PI * x / L);
            }
            //arriba
            else if (jj == N - 1) {
                A(k, k) = 1.0;
                b(k) = 0.0;
            }
            //izquierda
            else if (ii == 0) {
                A(k, k) = 1.0;
                b(k) = 0.0;
            }
            //derecha
            else if (ii == N - 1) {
                A(k, k) = 1.0;
                b(k) = 0.0;
            }
            
            //puntos internos
            else {
                //punto actual
                A(k, index(ii, jj, N)) = -4.0;
                
                // vecinos
                A(k, index(ii + 1, jj, N)) = 1.0; // derecha
                A(k, index(ii - 1, jj, N)) = 1.0; // izquierda
                A(k, index(ii, jj + 1, N)) = 1.0; // arriba
                A(k, index(ii, jj - 1, N)) = 1.0; // abajo

                b(k) = 0.0;
            }
        }
    }
}