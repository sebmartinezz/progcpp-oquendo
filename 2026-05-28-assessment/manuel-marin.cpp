#include <array>
#include <cmath>
#include <print>
#include <vector>
#include <string>

/* usamos array aunque usa memoria de stack, ya sabemos el tamaño de las matrices y vectores que son fijos, no cambian, para este ejemplo en 3D
por lo cual va ser mas rapido que usar vector o valarray  */
void matmu(const std::array<double, 9>& A, int mA, int nA, const std::array<double, 3>& B, int nB, std::array<double, 3>& C);


int main(int argc, char* argv[]){
    
    if (argc < 7) {
        std::println("No coloco la cantidad de argumentos esperados"); //verificar que si se esten dando la cantidad de datos
        return 1;
    }

    double ANGx {std::stod(argv[4])};
    double ANGy {std::stod(argv[5])};
    double ANGz {std::stod(argv[6])};
    double Cosx {std::cos(ANGx)};
    double Sinx {std::sin(ANGx)};
    double Cosy {std::cos(ANGy)};
    double Siny {std::sin(ANGy)};
    double Cosz {std::cos(ANGz)};
    double Sinz {std::sin(ANGz)};

    std::array<double, 3> Vec0 {std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])};
    std::array<double, 9> Rotx {1, 0, 0,   0, Cosx, -Sinx,   0, Sinx, Cosx};
    std::array<double, 9> Roty {Cosy, 0, Siny,   0, 1, 0,   -Siny, 0, Cosy};
    std::array<double, 9> Rotz {Cosz, -Sinz, 0,   Sinz, Cosz, 0,   0, 0, 1};
    std::array<double, 3> VecF {0.0, 0.0, 0.0};
    // 1. Rotación en X
    matmu(Rotx, 3, 3, Vec0, 1, VecF);
    Vec0 = VecF;

    // 2. Rotación en Y
    matmu(Roty, 3, 3, Vec0, 1, VecF);
    Vec0 = VecF;

    // 3. Rotación en Z
    matmu(Rotz, 3, 3, Vec0, 1, VecF);


    std::println("{:.8f} {:.8f} {:.8f}", VecF[0], VecF[1], VecF[2]);
}



void matmu(const std::array<double, 9>& A, int mA, int nA, const std::array<double, 3>& B, int nB, std::array<double, 3>& C)
{
  for (int ii = 0; ii < mA; ++ii) {  //filas
    for (int jj = 0; jj < nB; ++jj) {  //columnas
        C[ii*nB + jj] = 0.0;
        for(int kk = 0; kk < nA; ++kk){
            C[ii*nB + jj] += A[ii*nA + kk]*B[kk*nB + jj];
        }
    }
  }
}