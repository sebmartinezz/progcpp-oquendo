#include <vector>
#include <cmath>
#include <print>
#include <fstream>
#include <string>
#include <functional>

using vptr = std::vector<double>;

vptr sumasE (vptr x, vptr y, long N);
vptr m_b (vptr s, long N);


int main (int argc, char **argv)
{
    std::string fname = argv[1];

    std::vector<double> xdata;
    std::vector<double> ydata;

    double x {0.0};
    double y {0.0};
    
    std::ifstream fin(fname);
    while (fin>>x>>y){
        xdata.push_back(x);
        ydata.push_back(y);
    }

    fin.close();


    double e = 1.602176634e-19;
    double n = xdata.size();
    vptr sumas = sumasE(xdata, ydata, n); //Ex, Exx, Ey, Eyy, Exy
    vptr info = m_b(sumas, n); //m , b, delta_m, delta_b

    std::println("m  : {:25.16e}\nb  : {:25.16e}\ne_m: {:25.16e}\ne_b: {:25.16e}", info[0], info[1], info[2], info[3]);
    
    double hteo = 6.62607015e-34;
    double h = e*info[0];
    double e_h = std::fabs(1-h/hteo);
    double phi = -1* info[1];
    std::println("h  : {:25.16e}\ne_h:{:25.16e}\nphi: {:25.16e}\n", h, e_h, phi);

    return 0;
}


vptr sumasE (vptr x, vptr y, long N)
{
    double Ex{0}, Exx{0}, Ey{0}, Eyy{0}, Exy{0};

    for (long ii = 0;  ii<N ; ii++){
        Ex+=x[ii];
        Exx+=x[ii]*x[ii];
        Ey+= y[ii];
        Eyy+=y[ii]*y[ii];
        Exy += x[ii]*y[ii];
    }
    Ex = Ex/N;
    Exx = Exx/N;
    Ey = Ey/N;
    Eyy = Eyy/N;
    Exy = Exy/N;

    vptr S {Ex, Exx, Ey, Eyy, Exy};
    return S;
}

vptr m_b (vptr s, long N) 
{
    double aux1 = s[1]-s[0]*s[0];

    double m = (s[4]-s[0]*s[2])/aux1;
    double b = (s[1]*s[2]- s[0]*s[4])/aux1;

    double ss = (N/(N-2.0))*(s[3]-s[2]*s[2]-m*m*aux1);
    double delta_mm = ss/(N*aux1);
    double delta_bb = delta_mm*s[1];

    double delta_m = std::sqrt(delta_mm);
    double delta_b = std::sqrt(delta_bb);

    std::vector<double> i = {m, b, delta_m, delta_b};
    return i;
}