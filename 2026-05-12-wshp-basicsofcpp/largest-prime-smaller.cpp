#include <cmath>
#include <print>

bool prime (long n);
void largestprimesmallerthan(long m);

int main ( int argc, char **argv)
{
    long a = std::stol(argv[1]);
    largestprimesmallerthan(a);

    return 0;
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

void largestprimesmallerthan(long m)
{

    if (m<0){
        std::println("negative number, ignoring");
    }
    for (long ii=m; ii >= 2; ii--){
        if (prime(ii)){
            std::println("{}", ii);
            break;
        }
    }

}