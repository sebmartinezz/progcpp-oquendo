# include <fstream>
# include <cmath>
#include <print>


double potential(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h);
double electricfield(double x, double h);
int main(void)
{
    for (double x = 0; x <= 2.5; x= x+0.02){

        double teo = 2*std::sin(x)+2*x*std::cos(x);
        std::println("{:25.16e} {:25.16e} {:25.16e}", x, -teo, electricfield(x, 0.02));
    }

}
double potential(double x)
{
    return 2*x*std::sin(x);
}
double dev_central(double x, double h)
{
    return (potential(x+h)-potential(x-h))/(2*h);
}
double dev_central_richardson(double x, double h)
{
    double p = 2.0;
    double aux1 = std::pow(2, p)*dev_central(x, h/2)-dev_central(x, h);
    double aux2 = std::pow(2, p)-1;

    return aux1/aux2;
}
double electricfield(double x, double h)
{
    return -1 * dev_central_richardson(x, h); //retorna el campo eléctrico
}