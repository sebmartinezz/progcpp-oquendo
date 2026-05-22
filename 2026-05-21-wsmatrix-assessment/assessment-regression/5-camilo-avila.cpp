#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 
#include <print>

int main(int argc, char* argv[]) {

    std::ifstream fin(argv[1]); //Es para abrir el archivo usando lo escrito en la terminal. 
    
    std::vector<double> xdatos;
    std::vector<double> ydatos;
    double x, y;
    
    while (fin >> x >> y) {
        xdatos.push_back(x);
        ydatos.push_back(y);
    }
    fin.close();

    int N = xdatos.size();

    double suma_x = 0;
    double suma_y = 0;   
    double suma_xx = 0;
    double suma_yy = 0;
    double suma_xy = 0;
    
    for (int i = 0; i < N; ++i) {
        suma_x  += xdatos[i];
        suma_y  += ydatos[i];
        suma_xx += xdatos[i] * xdatos[i];
        suma_yy += ydatos[i] * ydatos[i]; 
        suma_xy += xdatos[i] * ydatos[i];
    }

    double Ex  = suma_x / N;
    double Ey  = suma_y / N;
    double Exx = suma_xx / N;
    double Eyy = suma_yy / N;
    double Exy = suma_xy / N;
    
    double m = (Exy - (Ex * Ey)) / (Exx - (Ex * Ex));
    double b = ((Exx * Ey) - (Ex * Exy)) / (Exx - (Ex * Ex));

    double s2 = (1.0 * N / (N - 2)) * (Eyy - (Ey * Ey) - (m * m * (Exx - (Ex * Ex))));
    
    double delta_m2 = s2 / (N * (Exx - (Ex * Ex)));
    double delta_b2 = delta_m2 * Exx;

    double error_m = std::sqrt(delta_m2);
    double error_b = std::sqrt(delta_b2);

    std::println("m = {:16.16e} Δm = {:16.16e}",m , error_m);
    std::println("b = {:16.16e} Δb = {:16.16e}",b , error_b);

    return 0;
}