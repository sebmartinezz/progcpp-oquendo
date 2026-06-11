#include <iostream>
#include <valarray>
#include <cmath>
#include <print>
#include "ivp_solver_amp.h"

typedef std::valarray<double> state_t;

void initial_conditions(state_t & y);
double print(const state_t & y, double time);
double maxamp (const state_t & amps);
double max_amp(double w);

int main(int argc, char **argv)
{
    std::println("{:.6e}", max_amp(0.1));
    return 0;

}
void initial_conditions(state_t & y)
{
    y[0] = 0.0; // position
    y[1] = 0.0;   // velocity
}

double print(const state_t & y, double time)
{
    //std::println("{:25.16e} {:25.16e} {:25.16e}", time, y[0], y[1]);
    return std::abs(y[0]);
}
double maxvectoramp (const state_t & amps){ //gives the max of vector amps defined in rk4, therefore, max amp for w in lambda function

    double max = amps[0]; //max starts in amps[0]

    for (int ii=1; ii<amps.size(); ii++){
        if (amps[ii]>max){
            max = amps[ii];
        }
    }
    return max;
}
double max_amp(double w){
    int N = 2;
    state_t y(N);
    state_t amplitudes((650.0-300.0)/0.01);
    initial_conditions(y);

        auto fderiv = [w] (const state_t & y, state_t & dydt, double t){
            const double W0 = 1.234;
            const double gamma = 0.1;
            const double A0 = 2.345;
            dydt[0] = y[1];
            dydt[1] = -W0*y[0] - gamma*y[1] + A0*std::cos(w*t);
        };
        integrate_rk4(fderiv, y, 300.0,650.0, 0.01, print, amplitudes);
        double max_amp = maxvectoramp(amplitudes);
        return max_amp;

}