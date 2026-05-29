#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <print>

using namespace std;

// Función para multiplicar una matriz 3x3 por un vecStor 3x1
vector<double> multiplyMatrixVector(const vector<double>& mat, const vector<double>& vec) {
    vector<double> result(3, 0.0);
    for (int i = 0; i < 3; ++i) {                   // Recorremos las 3 filas
        for (int j = 0; j < 3; ++j) {               // Recorremos las 3 columnas
            result[i] += mat[i * 3 + j] * vec[j];   // El índice i*3+j mapea la coordenada (i,j) de 2D a 1D
        }
    }
    return result;
}

// Matriz de rotación en X
vector<double> MatRx(double theta) {
    return {
        1.0, 0.0, 0.0,
        0.0, cos(theta), -sin(theta),
        0.0, sin(theta), cos(theta)
    };
}

// Matriz de rotación en Y
vector<double> MatRy(double theta) {
    return {
        cos(theta), 0.0, sin(theta),
        0.0, 1.0, 0.0,
        -sin(theta), 0.0, cos(theta)
    };
}

// Matriz de rotación en Z
vector<double> MatRz(double theta) {
    return {
        cos(theta), -sin(theta), 0.0,
        sin(theta), cos(theta), 0.0,
        0.0, 0.0, 1.0
    };
}

int main(int argc, char* argv[]) {
    // Validar el número de argumentos
    if (argc != 7) {
        cerr << "Uso incorrecto. Formato esperado: ./a.out vx vy vz thetax thetay thetaz" << endl;
        return 1;
    }

    // Convertir argumentos de texto a double
    vector<double> v = { stod(argv[1]), stod(argv[2]), stod(argv[3]) };
    double thetax = stod(argv[4]);
    double thetay = stod(argv[5]);
    double thetaz = stod(argv[6]);

    vector<double> Rx = MatRx(thetax);
    vector<double> Ry = MatRy(thetay);
    vector<double> Rz = MatRz(thetaz);

    // 2. Aplicar rotaciones sucesivamente: v' = Rz * Ry * Rx * v
    vector<double> v_rotX = multiplyMatrixVector(Rx, v);
    vector<double> v_rotXY = multiplyMatrixVector(Ry, v_rotX);
    vector<double> v_final = multiplyMatrixVector(Rz, v_rotXY);

    // 3. Imprimir el vector resultante
    std::print("{:.6} {:5.6} {:5.6}\n", v_final[0], v_final[1], v_final[2]);

    return 0;
}