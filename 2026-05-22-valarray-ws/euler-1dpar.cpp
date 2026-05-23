#include <iostream>
#include <valarray>
#include <cmath>
#include <print>
#include<fstream>

int main()
{
    //constants
    double G = -9.81; //m/s²
    double H = 25.98; //m
    double TF = 10.34535; //s
    double DT = 0.0001; //s
    double MASS = 0.87654;
    double K = 123.4567; //N/m
    double B = 1.33456;

    //system state
    //s[0] position
    //s[1] velocity
    std::valarray<double> s = {0.0, 0.0};
    std::valarray<double> DERIV (2);

    //initial conditions
    s[0]=H;
    s[1]=0.0;

    std::ofstream fout ("datos.txt");
    fout << 0.0 << "\t"<<s[0]<<"\t"<<s[1]<<"\n";

    //time loop 
    for (double t=0; t<=TF; t+=DT){
        DERIV[0]=s[1];
        DERIV[1]=G;     //fuerza de la gravedad

        double delta = -s[0];
        if (delta >=0){
            DERIV[1]+=(K/MASS)*delta;
            DERIV[1]-=B*DERIV[0];
        }
        s=s+DT*DERIV;
        fout << t << "\t"<<s[0]<<"\t"<<s[1]<<"\n";
    }
    fout.close();

    return 0;
}
