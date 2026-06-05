
#include <iostream>
#include <valarray>
#include <functional>

// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s+dt*dsdt;
 
        // write new state
        writer(s, t);
      }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{

    // vector to store derivs
    system_t dsdt(s.size());
    system_t k1(s.size());
    system_t k2(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf

        fderiv(s, dsdt, t);
        k1= dsdt;
        fderiv(s+k1*dt, dsdt, t+dt);
        k2= dsdt;
        s = s+0.5*dt*(k1+k2);

        writer(s, t);
      }


}