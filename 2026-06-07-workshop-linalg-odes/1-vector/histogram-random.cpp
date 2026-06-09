#include <vector>
#include <print>
#include <cmath>
#include <cassert>
#include <random>

#include<string>
#include <fstream>

void minmax (const std::vector<double>&v, std::vector<double>&minmax);
void randomize (std::vector<double>&v, long seed, double shape, double scale);

int main (int argc, char **argv)
{
    long nu = std::stol(argv[1]);
    long seedu = std::stol(argv[2]);
    double shapeu = std::stol(argv[3]);
    double scaleu = std::stol(argv[4]);
    
    std::vector<double> u (nu,0.0);
    randomize(u, seedu, shapeu, scaleu); //randomize a u

    std::ofstream fout("datoshistograma.txt");
    for (double x : u) {
    std::print(fout, "{}\n", x);
    }
    fout.close();

    return 0;
}

void randomize (std::vector<double>&v, long seed, double shape, double scale){
    
    std::mt19937 gen(seed);
    std::weibull_distribution<double> dis(shape, scale);


    for (int ii = 0; ii < v.size(); ii++) {
        v[ii] = dis(gen); // Le pasamos el motor a la distribución
    }

}