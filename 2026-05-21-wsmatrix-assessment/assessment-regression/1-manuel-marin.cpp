#include <print>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

std::vector<double> MinimosCuadrados(std::string filename);

int main (int argc, char *argv[]){
    std::string fname = argv[1];  //Se debe colocar primero el nombre del archivo donde esten los datos del experimento.
    std::vector<double> result = MinimosCuadrados(fname);
    std::string Gfname {argv[2]};  //Colocar de segundas el nombre del archivo donde se guardaran los resultados, para evitar sobreescrituras
    FILE * file = std::fopen(Gfname.c_str(), "w");
    std::println(file, "{:24.16e} {:24.16e} {:24.16e} {:24.16e}", result[0], result[1], result[2], result[3]);
    std::fclose(file);
    return 0;
}


std::vector<double> MinimosCuadrados(std::string filename){
    std::ifstream fname(filename);
    std::vector<double> xdata, ydata;
    double x, y;
    while (fname >> x >> y) { //reads two numbers until error or end of file
        xdata.push_back(x);
        ydata.push_back(y);
    }
fname.close();
    size_t n {xdata.size()};
    double sumx {0.0}, sumy {0.0}, sumx2 {0.0}, sumxy {0.0}, sumy2 {0.0};
    for (size_t ii {0}; ii < n; ii++){
        std::println("xdata[{}] = {:24.16e} ydata[{}] = {:24.16e}", ii, xdata[ii], ii, ydata[ii]); //Confirmar los datos leidos
        sumx += xdata[ii];
        sumy += ydata[ii];
        sumx2 += xdata[ii]*xdata[ii];
        sumxy += ydata[ii]*xdata[ii];
        sumy2 += ydata[ii]*ydata[ii];
}
    double Ex {sumx/n};
    double Ey {sumy/n};
    double Ex2 {sumx2/n};
    double Exy {sumxy/n};
    double Ey2 {sumy2/n};

    double m {(Exy - Ex*Ey)/(Ex2 - Ex*Ex)};
    double b {(Ex2*Ey - Ex*Exy)/(Ex2 - Ex*Ex)};
    double s2 {n*(Ey2 - Ey*Ey - m*m*(Ex2 - Ex*Ex))/((n-2))};
    double dm {std::sqrt(s2 / (n*(Ex2-Ex*Ex)))};
    double db {std::sqrt(dm*dm*Ex2)};
    return {m, b, dm, db};
}