// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>

template <class deriv_t, class system_t, class printer_t>
void integrate_rk4(deriv_t fderiv, system_t & s, double tinit, double tend, 
                    double dt, printer_t writer, system_t&amps)
{
    // vector to store derivs
    system_t dsdt(s.size());
    system_t k1(s.size());
    system_t k2(s.size());
    system_t k3(s.size());
    system_t k4(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) {
        fderiv(s, dsdt, t);
        k1 = dsdt;
        fderiv(s + dt*k1/2, dsdt, t+dt/2);
        k2 = dsdt;
        fderiv(s+dt*k2/2, dsdt, t+dt/2);
        k3=dsdt;
        fderiv(s+dt*k3, dsdt, t+dt);
        k4=dsdt;

        s = s + (dt/6.0)*(k1 + 2*k2+2*k3+k4);

        // write new state
        double amp = writer(s, t); //me devuelve s[0] y print
        amps[(t-tinit)/dt]= amp;
      }
}
