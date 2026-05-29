#include <print>
#include <cmath>
#include <valarray>
#include <string>

void multiplicacion_zy(const std::valarray<double> & z, 
                       const std::valarray<double> & y,
                        std::valarray<double> & r);

void multiplicacion_zyx(const std::valarray<double> & zy,
                        const std::valarray<double> & x,
                        std::valarray<double> & zyx);

void resultado(const std::valarray<double> & zyx, 
               const std::valarray<double> & vt,
                std::valarray<double> & res);

void imprimir(const std::valarray<double> & data);

int main(int argc, char** argv)
{

    std::valarray<double> vector_incial = {std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])};

    const double thetax = std::stod(argv[4]);
    const double thetay = std::stod(argv[5]);
    const double thetaz = std::stod(argv[6]);

    std::valarray<double> Rx = {1.0, 0.0, 0.0, 0.0, cos(thetax), -sin(thetax), 0.0, sin(thetax), cos(thetax)};
    std::valarray<double> Ry = {cos(thetay), 0.0, sin(thetay), 0.0, 1.0, 0.0, -sin(thetay), 0.0, cos(thetay)};
    std::valarray<double> Rz = {cos(thetaz), -sin(thetaz), 0.0, sin(thetaz), cos(thetaz), 0.0, 0.0, 0.0, 1.0};
    
    std::valarray<double> Rzy(9);
    std::valarray<double> Rzyx(9);
    std::valarray<double> Rzyxv(3);

    multiplicacion_zy(Rz, Ry, Rzy);
    multiplicacion_zyx(Rzy, Rx, Rzyx);
    resultado(Rzyx, vector_incial, Rzyxv);

    imprimir(Rzyxv);

    return 0;
}

void multiplicacion_zy(const std::valarray<double> & z, 
                       const std::valarray<double> & y,
                        std::valarray<double> & r)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            r[i * 3 + j] = 0.0;
            for(int k = 0; k < 3; k++){
                r[i * 3 + j] += z[i * 3 + k] * y[k * 3 + j];
            }
        }
    }
}

void multiplicacion_zyx(const std::valarray<double> & zy,
                        const std::valarray<double> & x,
                        std::valarray<double> & zyx)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            zyx[i * 3 + j] = 0.0;
            for(int k = 0; k < 3; k++){
                zyx[i * 3 + j] += zy[i * 3 + k] * x[k * 3 + j];
            }
        }
    }
}

void resultado(const std::valarray<double> & zyx, 
                       const std::valarray<double> & v,
                        std::valarray<double> & final)
{
   for(int i = 0; i < 3; i++) {
        final[i] = 0.0;
        for(int k = 0; k < 3; k++) {
            final[i] += zyx[i * 3 + k] * v[k];
        }
    }
}

void imprimir(const std::valarray<double> & data)
{
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 3; j++){
            std::print("{} ", data[i * 3 + j]);
        }
        std::println("");
    }
}