#include <iostream>
#include <cmath>

unsigned long long int repsquaremod(
    unsigned long long int base,
    unsigned long long int power,
    unsigned long long int prime
) {
    unsigned long long int second = 2LL;
    unsigned long long int solution = 1;

    while (power > 0) {
        if (power%second != 0) {
            solution = (solution * base) % prime;
            power -= power % second;
        }
        second *= 2;
        base = (base * base) % prime;
    }
    return solution;
}

int main() {
    unsigned int n, b;

    std::cin >> n;
    while (n--) {
        std::cin >> b;
        //std::cout << calc(b) << std::endl;
        std::cout << repsquaremod(2, b-2, 1000000007L) << std::endl;
    }
    return 0;
}
