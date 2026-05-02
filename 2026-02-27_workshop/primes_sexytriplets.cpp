#include <print>
#include <iostream>
#include <cmath>

bool prime (long n);
void cousin (long Nmin, long Nmax);
void sexytriplets(long Nmin, long Nmax);


int main(int argC, char **argv)
{
    
    long nmin =std::stol(argv[1]);
    long nmax =std::stol(argv[2]);

    sexytriplets(nmin, nmax);

    return 0;
}



void cousin (long Nmin, long Nmax){

    for(long ii = Nmin; ii<=Nmax; ii++){

        if(prime(ii) && prime(ii+4)){
            std::println("({}, {})", ii, ii+4);
        }
    }

}

bool prime (long n){

    if(n<=1){
        return false;
    }

    for(long i = 2; i <= std::sqrt(n)+1 ; i++){ //para mayores a sqrt(n) ya verifiqué con los menores, +1 para que no se trunque

        if(n%i==0){
            return false;
        }
    }
    return true;
}

void sexytriplets (long Nmin, long Nmax){
    for (long ii=Nmin; ii<=Nmax; ii++){

        if (prime(ii) and prime(ii+6) and prime (ii+12)){
            std::println("{}, {}, {}", ii, ii+6, ii+12);
        }
    }

}
