#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <iomanip>

std::vector<double> calculateLinearFit(const std::vector<double>& xdata, const std::vector<double>& ydata) {
    size_t N = xdata.size();

    // Calcular promedios usando std::accumulate
    double Ex = std::accumulate(xdata.begin(), xdata.end(), 0.0) / N;
    double Ey = std::accumulate(ydata.begin(), ydata.end(), 0.0) / N;

    double Exx = 0.0;
    double Exy = 0.0;
    double Eyy = 0.0;

    for (size_t i = 0; i < N; ++i) {
        Exx += xdata[i] * xdata[i];
        Exy += xdata[i] * ydata[i];
        Eyy += ydata[i] * ydata[i];
    }
    Exx /= N;
    Exy /= N;
    Eyy /= N;

    // Fórmulas para la pendiente (m) y el punto de corte (b)
    double denominator = Exx - (Ex * Ex);
    double m = (Exy - Ex * Ey) / denominator;
    double b = (Exx * Ey - Ex * Exy) / denominator;

    // Varianza de los residuos (s^2)
    double s2 = (static_cast<double>(N) / (N - 2)) * (Eyy - (Ey * Ey) - (m * m) * denominator);

    // Errores al cuadrado (Delta m^2 y Delta b^2)
    double dm2 = s2 / (N * denominator);
    double db2 = dm2 * Exx;

    // Extraer la raíz cuadrada de los errores (según indicación de la guía)
    double dm = std::sqrt(dm2);
    double db = std::sqrt(db2);

    // Retornamos los resultados ordenados en un vector empleando inicialización por lista
    return {m, b, dm, db};
}

int main(int argc, char* argv[]) {
    std::string fname = argv[1];
    std::ifstream fin(fname);
    std::vector<double> xdata;
    std::vector<double> ydata;
    double x, y;

    // Lectura indeterminada de datos (columna 1: x=frecuencia, columna 2: y=voltaje)
    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();

    // Ejecutar el ajuste y recibir el vector con los 4 resultados
    std::vector<double> res = calculateLinearFit(xdata, ydata);

    // Constantes físicas del enunciado
    const double e_charge = 1.602176634e-19;  // C
    const double h_accepted = 6.62607015e-34; // J*s

    // Mapeo de los índices del vector devuelto:
    // res[0] = m , res[1] = b , res[2] = dm , res[3] = db
    double h_calc = res[0] * e_charge;
    double dh_calc = res[2] * e_charge;
    double phi_calc = -res[1];
    double dphi_calc = res[3];

    // Mostrar resultados por pantalla con formato científico de alta precisión
    return 0;
}