#include <iostream>
#include <cstdlib>
#include <print> 
#include <cstdio> 
#include <eigen3/Eigen/Dense>
#include <complex>


void solvesystem(double k, double m1, double m2, FILE* archivo);

int main(int argc, char **argv) 
{
    
    if (argc != 4) 
    {
        std::println(stderr, "ERROR.\nUso:\n{} K M1 M2", argv[0]);
        return 1;
    }

    
    const double K  = std::atof(argv[1]);
    const double M1 = std::atof(argv[2]);
    const double M2 = std::atof(argv[3]);

    // para mandar los datos a un archivo de texto
    FILE* archivo = std::fopen("datos.txt", "a");
    if (!archivo) {
        std::println(stderr, "Error crítico: No se pudo abrir datos.txt");
        return 1;
    }

    
    std::print(archivo, "{}\t{}\t{}\t", K, M1, M2);
    
    
    solvesystem(K, M1, M2, archivo);
    
    
    std::fclose(archivo);
    
    return 0;
}


void solvesystem(double k, double m1, double m2, FILE* archivo) {
    //matriz 2x2  según la ecuación (6)
    Eigen::Matrix2d A;
    A(0, 0) = 2.0 * k / m1;
    A(0, 1) = -k / m1;
    A(1, 0) = -k / m2;
    A(1, 1) = 2.0 * k / m2;

    // Cálculo de los valores propios utilizando Eigen
    Eigen::EigenSolver<Eigen::Matrix2d> es(A);
    
    
    double ev1 = es.eigenvalues()[0].real();
    double ev2 = es.eigenvalues()[1].real();

    
    std::println(archivo, "{}\t{}", ev1, ev2);
}