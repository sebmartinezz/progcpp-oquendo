#include <valarray>
#include <cmath>
#include <print>
#include <cassert>

void crossprod (const std::valarray<double>&v, const std::valarray<double>& u, std::valarray<double>&vcrossu);
void velocity (const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&v);
void angularmom (double m, const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&L);
void centracc (const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&ac);

int main(int argc, char **argv){

    std::valarray<double> w = {1, 2.567, 9};
    std::valarray<double> r = {12, 67.875, 123.987};

    std::valarray<double> v (3);
    std::valarray<double> Lo (3);
    std::valarray<double> acc (3);

    double mass = 10.234;

    velocity(r, w, v);
    angularmom(mass, r, w, Lo);
    centracc(r, w, acc);

    std::println("w:{} \nr:{} \nv:{} \nLo:{} \nacc:{}", w, r, v, Lo, acc);

    return 0;
}

void crossprod (const std::valarray<double>&v, const std::valarray<double>& u, std::valarray<double>&vcrossu){
    assert(v.size()==u.size());
    assert(u.size()==vcrossu.size());
    assert(vcrossu.size()==3);

    vcrossu[0] = v[1]*u[2]-v[2]*u[1];
    vcrossu[1] = -(v[0]*u[2]-v[2]*u[0]);
    vcrossu[2] = v[0]*u[1]-v[1]*u[0];

}

void velocity (const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&v){
    assert(r.size()==omega.size());
    assert(omega.size()==v.size());
    assert(v.size()==3);
    crossprod(omega, r, v);
}
void angularmom (double m, const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&L){
    assert(r.size()==omega.size());
    assert(omega.size()==L.size());
    assert(L.size()==3);
    
    std::valarray<double> vaux (3);
    crossprod(omega, r, vaux);
    crossprod(r, vaux, L);
    L=m*L;
}
void centracc (const std::valarray<double>&r, const std::valarray<double>&omega, std::valarray<double>&ac){
    assert(r.size()==omega.size());
    assert(omega.size()==ac.size());
    assert(ac.size()==3);
    
    
    std::valarray<double> vaux (3);
    crossprod(omega, r, vaux);
    crossprod(omega, vaux, ac);
}