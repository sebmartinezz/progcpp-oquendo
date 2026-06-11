#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC);

bool are_commutative (const std::vector<double> &A,
                    const std::vector<double> &B, double eps);

int main(int argc, char **argv){


    return 0;
}

bool are_commutative (const std::vector<double> &A,
                    const std::vector<double> &B, double eps){

    assert(A.size()==B.size());
    int m = std::sqrt(A.size());

    std::vector<double>AB(A.size(), 0.0);
    matmul(A, m, m, B, m, m, AB, m, m);

    std::vector<double>BA(A.size(), 0.0);
    matmul(B, m, m, A, m, m, BA, m, m);

    std::vector<double> Id (A.size(), 0.0);
    for (int jj=0; jj<m; jj++){
        Id[m*jj+jj]=1.0;
    }

    for (int ii=0; ii<m; ii++){
        for (int jj=0; jj<m; jj++){
            if (std::abs(AB[ii*m+jj]-BAii*m+jj])>=eps){
                return false;
            }
        }
    }
    return true;

}


void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC)
{
  assert(nA==mB);
  assert(mC==mA);
  assert(nC==nB);

  for (int ii = 0; ii<mC; ii++) //filas
  {
    for (int jj=0; jj<nC; jj++) //columnas
    {
      C[ii*nC+jj]=0.0;
      for (int kk=0; kk<nA; ++kk)
      {
        C[ii*nC+jj]+= A[ii*nA + kk]*B[kk*nB + jj];
      }

    }
  }
}
