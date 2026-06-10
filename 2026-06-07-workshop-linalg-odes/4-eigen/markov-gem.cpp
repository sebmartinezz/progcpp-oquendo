#include <iostream>
#include <iomanip>
#include <Eigen/Dense> // Cabecera principal de Eigen para álgebra lineal

int main() {
    // Configuración de formato para mostrar 6 decimales en la consola
    std::cout << std::fixed << std::setprecision(6);

    // 1. Definición de la matriz de transición A (3x3)
    Eigen::Matrix3d A;
    A << 0.8, 0.2, 0.1,
         0.1, 0.7, 0.3,
         0.1, 0.1, 0.6;

    // 2. Definición del vector de estado inicial x(0)
    // El sistema empieza en el estado 1 de forma determinista: [1.0, 0.0, 0.0]
    Eigen::Vector3d x0(1.0, 0.0, 0.0);

    std::cout << "=========================================" << std::endl;
    std::cout << "   CADENAS DE MARKOV (EIGEN C++)" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Vector inicial x(0): [" << x0.transpose() << "]\n\n";

    // -------------------------------------------------------------------------
    // PREGUNTA 1: Vector de probabilidad tras 3 pasos (k = 3)
    // -------------------------------------------------------------------------
    // Calculamos de forma directa x(3) = A * A * A * x(0)
    Eigen::Vector3d x3 = A * A * A * x0;

    std::cout << "1. Distribucion de probabilidad tras 3 pasos (x(3)):" << std::endl;
    std::cout << "   [" << x3.transpose() << "]\n\n";

    // -------------------------------------------------------------------------
    // PREGUNTA 2: Valor a largo plazo (Estado Estacionario Exacto)
    // -------------------------------------------------------------------------
    // Buscamos resolver el sistema: A * q = q  =>  (A - I) * q = 0
    // sujeto a la restricción de que la suma de sus componentes sea igual a 1.
    
    Eigen::Matrix3d M = A - Eigen::Matrix3d::Identity(); // M = A - I
    
    // Reemplazamos la última fila para imponer la condición: q_1 + q_2 + q_3 = 1
    M.row(2) << 1.0, 1.0, 1.0; 
    
    // Vector columna del lado derecho (0 para las primeras filas, 1 para la condición de suma)
    Eigen::Vector3d b(0.0, 0.0, 1.0);

    // Resolvemos de forma exacta usando descomposición QR de la matriz modificada
    Eigen::Vector3d q = M.colPivHouseholderQr().solve(b);

    std::cout << "2. Valor a largo plazo (Estado estacionario analitico):" << std::endl;
    std::cout << "   [" << q.transpose() << "]\n";
    std::cout << "=========================================" << std::endl;

    return 0;
}