#include <print>
#include <cmath>

void square (long n, std::string m); //does a square of side n stars

int main (int argc, char **argv){
    
    long a = std::stol(argv[1]);
    std::string b = argv[2];
    square (a, b);
}

void square (long n, std::string m){

    for (long ii=1; ii<=n; ii++){ //filas
        for (int jj=1; jj<=n; jj++){ //columnas

            if (ii==1 || jj == 1 || ii==n || jj==n){
                std::print("{}", m);
            }else{
                std::print(" ");
            }

        }
        std::println(""); //salta fila al pasar por todas las columnas de la fila
    }
}