#include<print>
#include<cmath>

double babsqrt (double s, long n);

int main (int argc, char **argv){

    double a = std::stod(argv[1]);
    double b = std::stol(argv[2]);
    double root = babsqrt (a, b);

    //std::println("{}", root);

    return 0;
}

double babsqrt (double s, long n){

    double x = 1.0;
    double xnew{0.0};

    for (long ii= 0; ii<= n; ii++){

        xnew = (x+s/x)/2.0;

        //calculamos diferencia relativa e imprimimos
        double diff = std::fabs(1- x/xnew);
        std::println("{:5} {:25.16e} {:25.16e}", ii, xnew , diff);

        x=xnew;
    }

    return x;
}