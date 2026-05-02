#include <print>
#include <cmath>


void triplet (long&founda, long&foundb, long&foundc);

int main (int argc, char **argv){

    long foundA{0}, foundB{0}, foundC{0};
    triplet(foundA, foundB, foundC);
    long prod = foundA*foundB*foundC;
    std::println("{} {} {} {}", foundA, foundB, foundC, prod);
    return 0;
}


void triplet (long&founda, long&foundb, long&foundc){

    long a{1};

    while (a<=333){
        long b=a+1;
        while(b< 1000){

            long c= 1000-a-b;
            if(a*a+b*b==c*c){
                
                founda= a;
                foundb =b;
                foundc= c;
                return;
            }
            b++;
        }
        a++;
    }

}