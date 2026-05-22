#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <print> 

double promedio(const std::vector<double>& v);
double promedio_cuadrado(const std::vector<double>& v);
double promedio_producto(const std::vector<double>& x, const std::vector<double>& y);

// Calcula el promedio simple de un vector: Ex, Ey (Ec. 1 y 2)
double promedio(const std::vector<double>& v) 
{
    if (v.empty()) return 0.0;
    double suma = 0.0;
    
    for (size_t i = 0; i < v.size(); ++i) {
        suma += v[i];
    }
    return suma / v.size();
}

// Calcula el promedio de los cuadrados: Exx, Eyy (Ec. 3)
double promedio_cuadrado(const std::vector<double>& v) 
{
    if (v.empty()) return 0.0;
    double suma = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        suma += v[i] * v[i];
    }
    return suma / v.size();
}

// Calcula el promedio del producto de dos vectores: Exy (Ec. 4)
double promedio_producto(const std::vector<double>& x, const std::vector<double>& y) 
{
    if (x.empty() || x.size() != y.size()) return 0.0;
    double suma = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        suma += x[i] * y[i];
    }
    return suma / x.size();
}

int main(int argc, char* argv[]) 
{
    
    /*para pasar los datos desde un archivo de texto de forma rapida. 
    Poner el nombre del archivo de los datos del ejercicio como argumento al ejecutar el programa. Como ./a.out datos.txt (ahi deben estar los datos que da el ejercicio)
    */

    if (argc < 2) {
        std::println(stderr, "Uso: {} <nombre_del_archivo.txt>", argv[0]);
        return 1;
    }

   
    std::ifstream fin(argv[1]);
    if (!fin) {
        std::println(stderr, "Error: No se pudo abrir el archivo.");
        return 1;
    }

    
    std::vector<double> xdata;
    std::vector<double> ydata;
    double x, y;

    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();

   
    if (xdata.size() < 3) {
        std::println(stderr, "Error: Se necesitan al menos 3 puntos para calcular incertidumbres.");
        return 1;
    }

    
    double N = static_cast<double>(xdata.size());

   
    double Ex  = promedio(xdata);
    double Ey  = promedio(ydata);
    double Exx = promedio_cuadrado(xdata);
    double Eyy = promedio_cuadrado(ydata);
    double Exy = promedio_producto(xdata, ydata);

    double denominador = Exx - Ex * Ex;
    double m = (Exy - Ex * Ey) / denominador;
    double b = (Exx * Ey - Ex * Exy) / denominador;


    double s2 = (N / (N - 2.0)) * (Eyy - Ey * Ey - m * m * denominador);
    double Dm2 = s2 / (N * denominador);
    double Db2 = Dm2 * Exx;

    double Dm = std::sqrt(Dm2);
    double Db = std::sqrt(Db2);

    constexpr double e = 1.602176634e-19;
    double h = m * e;
    double phi = -b;

    
    constexpr double h_real = 6.62607015e-34;
    double error = std::abs(h - h_real) / h_real * 100.0;

   
    std::println("--- Resultados del Ajuste ---");
    std::println("N                     = {}", static_cast<int>(N));
    std::println("m                     = {:.6e}", m);
    std::println("b                     = {:.6e}", b);
    std::println("Delta m               = {:.6e}", Dm);
    std::println("Delta b               = {:.6e}", Db);
    std::println("--- Constantes Físicas Calculadas ---");
    std::println("h                     = {:.6e} J·s", h);
    std::println("phi                   = {:.6e} eV", phi);
    std::println("Error porcentual h    = {:.4f}%", error);

    return 0;
}