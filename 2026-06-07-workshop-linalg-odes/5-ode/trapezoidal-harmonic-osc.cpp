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
    int N = 2;
    state_t y(N);
    initial_conditions(y);
    const double omega = 0.9876;

    auto f = [omega](const state_t & y, state_t & dydt, double t){
      dydt[0] = y[1];
      dydt[1] = -omega*omega*y[0];
    };

    //integrate_euler(fderiv, y, 0.0, 100.0, 0.001, print);
    //integrate_rk4(f, y, 0.0, 100.0, 0.1, print);
    integrate_crank_nicolson(f, y, 0.0, 100.0, 0.1, print);
    return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 1.2334; // position
  y[1] = 0.0; // velocity
}

void print(const state_t & y, double time)
{
  std::println("{:25.16e} {:25.16e} {:25.16e}", time, y[0], y[1]);
}
