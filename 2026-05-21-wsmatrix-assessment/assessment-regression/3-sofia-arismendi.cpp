#include <vector>
#include <print>
#include <string>
#include <fstream>
#include <numeric>
#include <cmath>

struct ResultadosRegresion { //Agrupar variables de diferentes nombres o tipos bajo un nombre en comun
    double m;
    double b;
    double delta_m;
    double delta_b;
};

ResultadosRegresion arreglos(const std::vector<double>& datax, const std::vector<double>& datay);

// Al ser 'inline', el compilador la pega directamente donde se usa, eliminando el costo de llamarla.
inline double E(double sumatoria, size_t N) {
    if (N == 0) { return 0.0 ; }
    else { return sumatoria / static_cast<double>(N); }  //Cuidado con no dividir doubles entre enteros
}

int main (int argc, char* argv[])
{
    if (argc < 2) {
        std::println("Error: Falta el nombre del archivo de datos.");
        return 1;
    }

    std::string fname = argv[1];
    std::ifstream fin(fname);

    std::vector<double> datax;
    std::vector<double> datay;

    double x= 0.0;
    double y= 0.0;

    while (fin >> x >> y) {
        datax.push_back(x);
        datay.push_back(y);
    }

    fin.close();

    if (datax.size() < 3) {
        std::println("Error: Se necesitan al menos 3 puntos de datos para calcular las incertidumbres.");
        return 1;
    }

    auto [m, b, delta_m, delta_b] = arreglos(datax, datay); //Desempaquetar los 4 arreglos usando Structured Binding

    //Constantes para la prueba del efecto fotoelectrico
    const double e_carga = 1.602176634e-19; // Carga del electrón en Culombios
    const double h_teorico = 6.62607015e-34; // Valor esperado de Planck

    //Variables prueba del efecto fotoelectrico
    double h_experimental = m * e_carga;
    double delta_h = delta_m * e_carga;
    double phi_experimental = -b; // Función de trabajo (phi = -b)
    double delta_phi = delta_b; // La incertidumbre se mantiene igual en magnitud

    double error_porcentual_h = std::abs((h_experimental - h_teorico) / h_teorico) * 100.0;

    std::println("m = {}", m);
    std::println("b = {}", b);
    std::println("Δm = {}", delta_m);
    std::println("Δb = {}", delta_b);

    std::println("Para la prueba del efecto fotoelectrico:");
    std::println("h_exp = {}", h_experimental);
    std::println("Δh = {}", delta_h);
    std::println("phi_exp = {}", phi_experimental);
    std::println("Δphi = {}", delta_phi);
    std::println("error_h = {}", error_porcentual_h);
}

ResultadosRegresion arreglos(const std::vector<double>& datax, const std::vector<double>& datay) {

    size_t N = datax.size();
    if (N == 0) return {0.0, 0.0, 0.0, 0.0} ; //Retornar los 4 doubles que espera

    double sumaX = 0.0;
    double sumaY = 0.0;
    double sumaXX = 0.0;
    double sumaYY = 0.0;
    double sumaXY = 0.0;

    for (size_t i = 0; i < N; ++i) { //En un solo bucle se generan todas las sumatorias, en lugar de consumir memoria RAM haciendolo individualmente
        double xi = datax[i];
        double yi = datay[i];

        sumaX  += xi;
        sumaY  += yi;
        sumaXX += xi * xi;
        sumaYY += yi * yi;
        sumaXY += xi * yi;
    }   

    double Ex  = E(sumaX, N);
    double Ey  = E(sumaY, N);
    double Exx = E(sumaXX, N);
    double Eyy = E(sumaYY, N);
    double Exy = E(sumaXY, N);

    double denominador = Exx - (Ex * Ex); //Optimizar código y evitar repetirse

    double m = (Exy - (Ex * Ey)) / denominador ;
    double b = ((Exx * Ey) - (Ex * Exy)) / denominador ;
    double s2 = (static_cast<double>(N) / (N - 2.0)) * (Eyy - (Ey * Ey) - (m * m *denominador));
    double delta_m2 = s2 / (static_cast<double>(N) * denominador) ;
    double delta_b2 = delta_m2 * Exx ;
    
    return {m, b, std::sqrt(delta_m2), std::sqrt(delta_b2)};
}