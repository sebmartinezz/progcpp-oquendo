#include <iostream>

int main(void)
{
    int i =0;
    std::cout<<"write an integer:";
    std::cin >>i;
    if(i<0) {
        std::cout<<"negative\n";
    } else if (i==0) {
        std::cout<<"zero\n";
    } else {
        std::cout<<"positive\n";
    }

    return 0;
}