#include<iostream>

//init; 
//while (condition) { … ; change; }

int main(void){

    int n = 1; //start
    while (n<=10){ //condition
        std::cout<<n<<"\n";
        ++n; //change
    }

    return 0;
}