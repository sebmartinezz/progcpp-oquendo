#include<print>
#include<cmath>
#include<cstdio>

bool isprime (long m);
void sumprimes (long a, std::string fname);

int main (int argc, char **argv){

    long A = std::stol(argv[1]);
    sumprimes(A, "sump.txt");

    return 0;
}

bool isprime (long m){

    if (m<=1){
        return false;
    }
    if (m==2){
        return true;
    }

    for (long ii=2; ii<=std::sqrt(m); ii++ ){
        if(m%ii == 0){
            return false;
        }
    }

    return true;
}

void sumprimes(long a, std::string fname){

    FILE*file=std::fopen(fname.c_str(), "w");

    long sum {0};
    for (long jj=0;jj<=a;jj++){
        if (isprime(jj)){
            sum +=jj;
        }
    }

    std::println(file, "{}", sum);
    std::fclose(file);
}
