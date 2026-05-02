// Basic numerical derivatives implementation
#include <string>
#include <cmath>
#include <print>
#include <functional>

double fun(double x); // 1d function
double g (double x);
double dforward(double x, double h, std::function<double(double)> f);
double dcentral(double x, double h, std::function<double(double)> f);

int main (int argc, char *argv[])
{
  double x = 10.234;
  double h = 1.0e-6;
  std::println("{}", dforward(x, h, fun));
  std::println("{}", dcentral(x, h, fun));
  std::println("{}", dcentral (x, h, g));
  
  return 0;
}


double fun(double x)
{
  return 2*std::sin(x*x) + 4/(x*x);
}

double g (double x){
  return std::cos(x+1)+2*x*x*x*x;
}



double dforward(double x, double h, std::function<double(double)> f)
{
  return (f(x+h) - f(x))/(h);
}

double dcentral(double x, double h, std::function<double(double)> f)
{
  return (f(x+h) - f(x-h))/(2*h);
}
