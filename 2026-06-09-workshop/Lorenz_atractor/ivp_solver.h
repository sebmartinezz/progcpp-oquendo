// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>


 //Plantilla de función para trabajar con cualquier tipo de dato. solo lo puedo poner en los .h
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
  //Vector para guardar las derivadas
    system_t dsdt(s.size());


    // loop temporal
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
       // TODO: Complete the code here
 
        s = s + dt*dsdt;

        // write new state
        writer(s, t);
      }
}
template <class deriv_t, class system_t, class printer_t>
void integrate_Heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
  //Vector para guardar las derivadas
    system_t dsdt(s.size());
    system_t k1(s.size());
    system_t k2(s.size());

    // loop temporal
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);
        k1 = dsdt;
        fderiv(s + dt*k1, dsdt, t + dt);
        k2 = dsdt;
 
        s = s + (dt/2.0)*(k1 + k2);

        // write new state
        writer(s, t);
      }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_RK4(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
  //Vector para guardar las derivadas
    system_t dsdt(s.size());
    system_t k1(s.size());
    system_t k2(s.size());
    system_t k3(s.size());
    system_t k4(s.size());

    // loop temporal
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);
        k1 = dsdt;
        fderiv(s + dt*(k1/2.0), dsdt, t + (dt/2.0));
        k2 = dsdt;
        fderiv(s + dt*(k2/2.0), dsdt, t + (dt/2.0));
        k3 = dsdt;
        fderiv(s + dt*k3, dsdt, t + dt);
        k4 = dsdt;

        s = s + (dt/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);

        // write new state
        writer(s, t);
      }
}