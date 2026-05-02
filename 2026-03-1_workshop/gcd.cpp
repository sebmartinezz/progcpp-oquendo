#include<print>
#include<cmath>

long gcd (long a, long b);

int main (int argC, char **argv){

    long m = std::stol(argv[1]);
    long n = std::stol(argv[2]);
    std::println("{}", gcd(m,n));
    return 0;
}

long gcd (long a, long b){

    long ii=0;
    
    if (a<=b){
        ii = a;
        while (a%ii != 0 || b%ii != 0){
            ii--;
        }
    }else{
        ii = b;
        while (a%ii != 0 || b%ii != 0){
            ii--;
        }
    }

    return ii;

}