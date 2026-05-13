/*
lee dos float de terminal: uno el radio y otro la incertidumbre.
funcion print área del circulo: pi*r*r
propagated uncertainty: 2*pi*r*delta-r
*/

#include <cmath>
#include <print>

void area (float r, float dr);

int main(int argc, char ** argv)
{
    float R = std::stof(argv[1]);
    float DR = std::stof(argv[2]);

    area(R, DR);
    return 0;
}

void area (float r, float dr)
{
    float area = M_PI*r*r;
    float uncert = 2*M_PI*r*dr;

    //acortar incertidumbre
    int decimales = 0;
    double copia_u = uncert;

    if (copia_u < 1) {
        while (copia_u < 1) {
            copia_u *= 10;
            decimales++; // cuantas comas pa la der
        }
    } else {
        while (copia_u >= 10) {
            copia_u /= 10;
            decimales--; // cuantas comas pa la izq
        }
    }

    double factor = std::pow(10, -decimales); 
    //redondeo manual de u
    double u_final = (int)(uncert / factor + 0.5) * factor;

    //redondeo del area en el mismo factor que u
    double a_final = (int)(area / factor + 0.5) * factor;

    int d_output = 0;

    if (decimales > 0) {
        d_output = decimales;
    } else {
        d_output = 0;
    }
    
    std::println("{:.{}f} {:.{}f}", a_final, d_output, u_final, d_output);
}