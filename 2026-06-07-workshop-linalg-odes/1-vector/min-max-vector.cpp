#include <vector>
#include <print>
#include <cmath>
#include <cassert>

void minmax (const std::vector<double>&v, std::vector<double>&minmax);
void argminmax (const std::vector<double>&v, std::vector<long>&argminmax);

int main (int argc, char **argv)
{
    std::vector<double> u = {200.18, 4, 98, 1.21, 3, 4.5, 12, 1837678634, 4, 5.987, 12345.987};
    std::vector<double> minmaxu (2, 0.0);
    std::vector<long> argminmaxu (2, 0);

    minmax(u, minmaxu);
    argminmax(u, argminmaxu);

    std::println("{} {}", minmaxu, argminmaxu);

    return 0;
}

void minmax (const std::vector<double>&v, std::vector<double>&minmax){

    assert(minmax.size()==2);
    assert(v.size()!=0);

    minmax[0] = v[0]; //min
    minmax[1] = v[0]; //max

    for (int ii=1; ii<v.size(); ii++){
        if (v[ii]<minmax[0]){
            minmax[0]= v[ii];
        }
        if (v[ii]>minmax[1]){
            minmax[1] = v[ii];
        }
    }
}

void argminmax (const std::vector<double>&v, std::vector<long>&argminmax){
    
    assert(argminmax.size()==2);
    assert(v.size()!=0);

    argminmax[0] = 0; //argmin
    argminmax[1] = 0; //argmax

    for (int ii=1; ii<v.size(); ii++){
        if (v[ii]< v[argminmax[0]]){
            argminmax[0]=ii;
        }
        if (v[ii]>v[argminmax[1]]){
            argminmax[1]=ii;
        }
    }
}