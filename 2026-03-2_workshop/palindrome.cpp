#include <print>
#include <cmath>
#include <string>


bool ispalindrome (long n);

int main (int argc, char **argv){

    long a = std::stol(argv[1]);
    
    if (ispalindrome(a)){
        std::println("es palindromo");
    }else{
        std::println("no es palindromo");
    }

    return 0;
}

bool ispalindrome (long n){

    std::string s =std::to_string(std::abs(n));

    for (long i=0; i <= (s.length()/2)+1 ; i++){
        if(s[i]!= s[s.length()-1-i]){
            return false;
        }
    }

    return true;
}