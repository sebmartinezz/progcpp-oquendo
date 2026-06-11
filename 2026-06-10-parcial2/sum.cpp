#include <vector>
#include <print>

int main (){

    std::vector<int> numbers = {0,1,2};
    int sum =0;
    for (int i =0; i<numbers.size(); i++){
        sum+=numbers.at(i);
    }
    std::println("{}", sum);
}