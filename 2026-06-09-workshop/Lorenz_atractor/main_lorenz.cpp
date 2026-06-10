#include <iostream>
#include <valarray>
#include <cmath>
#include <print>
#include "ivp_solver.h"

typedef std::valarray<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
{
    int N = 3;
    state_t y(N);
    initial_conditions(y);
    integrate_Heun(fderiv, y, 0.0, 100.0, 0.001, print);
    return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 1; // x
  y[1] = 1; // y
  y[2] = 1; // z
}

void print(const state_t & y, double time)
{
  std::println("{:25.16e} {:25.16e} {:25.16e}", y[0], y[1], y[2]);
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
    double SIGMA = 10.0;
    double RHO = 28.0;
    double BETA = 8.0/3.0;
    dydt[0] = SIGMA*(y[1] - y[0]); //dx/dt
    dydt[1] = y[0]*(RHO - y[2]) - y[1]; //dy/dt
    dydt[2] = y[0]*y[1] - BETA*y[2]; //dz/dt

}