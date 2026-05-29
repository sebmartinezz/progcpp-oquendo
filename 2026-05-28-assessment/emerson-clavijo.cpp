#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

/*Nota: Al jugar con los casos de prueba hay algunos que usan digitos de pi.
Se recomienda usar M_PI, ya que esos decimales faltantes en ocasiones
hace que el resultado difiera mucho. Como en la ultima prueba*/

void print_matrix(std::vector<double> & data, int m, int n);

void matmul(const std::vector<double> & A, int mA, int nA,
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C, int mC, int nC);

std::vector<double> transfor(const std::vector<double> & axis_z, int mz, int nz,  
                             const std::vector<double> & axis_y, int my, int ny,
                             const std::vector<double> & axis_x, int mx, int nx);
            
int main(int argc, char* argv[]){
    if(argc<7){
        std::cout<<"faaltan datos, recuerda deben ser:"<<"\n"<<
                    "coordenadas actuales: x, y, z"<<"\n"<<
                    "y angulos de rotacion de x, y, z";
        return 0;            
    } 

    //vector a rotar
    std::vector<double> coord = {std::stod(argv[1]),
                                 std::stod(argv[2]),
                                 std::stod(argv[3])};


    //angulos de rotación, los llame alfa porque era más corto que tetha

    double alfa_x{std::stod(argv[4])};
    double alfa_y{std::stod(argv[5])};
    double alfa_z{std::stod(argv[6])};


    //matrices de rotacion
    std::vector<double> axis_x{1, 0, 0, 0, std::cos(alfa_x), -std::sin(alfa_x),
                               0, std::sin(alfa_x), std::cos(alfa_x)};

    std::vector<double> axis_y{std::cos(alfa_y), 0, std::sin(alfa_y), 0, 1, 0,
                               -std::sin(alfa_y), 0, std::cos(alfa_y)};
                               
    std::vector<double> axis_z{std::cos(alfa_z), -std::sin(alfa_z), 0,
                               std::sin(alfa_z), std::cos(alfa_z), 0,
                                0, 0, 1};                           


    //aplicación de la transformacion lineal                            
    std::vector<double> mat_trans = transfor(axis_z, 3, 3,
                                             axis_y, 3, 3,
                                             axis_x, 3, 1);

    std::vector<double> new_vector(3, 0.0);
    matmul(mat_trans, 3, 3, coord, 3, 1, new_vector, 3, 1);
    print_matrix(new_vector, 3, 1);   


    return 0;
}



void print_matrix(std::vector<double> & data, int m, int n){
    std::cout<<"\n";
    
    for(int ii{0}; ii < n; ii++){
        for(int jj{0}; jj < m; jj++){
            std::cout<<data[ii*m + jj]<<" ";
        }
        std::cout<<"\n";
    }
}


void matmul(const std::vector<double> & A, int mA, int nA,
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C, int mC, int nC)
{
    assert(nA == mB);

    for (int ii = 0; ii < mC; ++ii) { // filas
        for (int jj = 0; jj < nC; ++jj) { // columnas
            C[ii*nC + jj] = 0.0;
            for (int kk = 0; kk < nA; ++kk) {
                C[ii*nC + jj] += A[ii*nA + kk]*B[kk*nB + jj];
            }
        }
    }
}

/* aplicar varias matrices a un vector es: A1*A2*A3*v
siendo A_i matrices, multiplicamos primero las matrices entre si
A1*A2*A3*v = (A1*A2*A3)*v */

std::vector<double> transfor(const std::vector<double> & axis_z, int mz, int nz,  
                             const std::vector<double> & axis_y, int my, int ny,
                             const std::vector<double> & axis_x, int mx, int nx){

    assert(nz==my && ny==mx);
                                
    std::vector<double> aux1(9, 0.0);  
    matmul(axis_z, 3, 3, axis_y, 3, 3, aux1, 3, 3);
    std::vector<double> transform(9, 0.0);
    matmul(aux1, 3, 3, axis_x, 3, 3, transform, 3, 3);

    return transform;                            
} 