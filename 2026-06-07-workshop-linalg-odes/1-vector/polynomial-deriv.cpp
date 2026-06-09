#include <vector>
#include <print>
#include <cmath>
#include <cassert>

void derivpol (const std::vector<double>&v, std::vector<double>&deriv);

int main (int argc, char **argv)
{
    std::vector<double> u = {1, 3, 4.5, 12, 4, 5.987};
    std::vector<double> du (u.size()-1, 0.0);

    derivpol(u, du);
    std::println("{}", du);

    return 0;
}

void derivpol (const std::vector<double>&v, std::vector<double>&deriv)
{
    assert(deriv.size()==v.size()-1);
    for (int ii = 0; ii<deriv.size(); ii++){
        deriv[ii] = (ii+1)*v[ii+1];
    }
    
}