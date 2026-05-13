#include <cmath>
#include <print>
#include <string>

//The program must read a number of four digits and print the digits, separated by a space

void digits (int n);

int main ( int argc, char **argv)
{
    int N =std::stoi(argv[1]);
    digits(N);

    return 0;
}

void digits (int n)
{
    if (n<0){
        std::println("Negative number. Ignoring");
        return;
    }

    std::string s = std::to_string(n);
    std::string inicial = "0000";
    if (s.length()>4){
        std::println("Number has more than 4 digits. Ignoring");
        return;
    }
    
    for (int ii=0; ii<s.length(); ii++)
    {
        inicial[4 - s.length() + ii] = s[ii];
    }

    std::println("{} {} {} {}", inicial[0], inicial[1], inicial[2], inicial[3]);
}