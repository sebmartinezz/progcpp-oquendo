#include "./pg.h"

bool isprime ( long n)
{
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

long pg (long n)
{
    long counter = 0;

    for (long x=2; x <= 1e305; x++)
    { 
        if (isprime(x) && isprime(x+2)){
            counter ++;
        }
        if (counter == n){
            return x;
        }
    }
    return 0;
}