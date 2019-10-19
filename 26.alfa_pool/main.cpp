#include <iostream>
#include <cmath>

//unsigned long long int repsquaremod(
//    unsigned long long int base,
//    unsigned long long int power,
//    unsigned long long int prime
//) {
//    unsigned long long int second = 2LL;
//    unsigned long long int solution = 1;
//
//    while (power > 0) {
//        if (power%second != 0) {
//            solution = (solution * base) % prime;
//            power -= power % second;
//        }
//        second *= 2;
//        base = (base * base) % prime;
//    }
//    return solution;
//}

unsigned long int ans[100000];

unsigned long int calc(unsigned int b) {
    unsigned long int s = 0;
    unsigned int j;
    if (ans[b] > 0) {
        return ans[b];
    }
    for (j=2; j<=b; j*=2) {
        //std::cout << "b:" << b-j+1 << std::endl;
        s = (s + calc(b-j+1)) % 1000000007L;
    }
    ans[b] = s;
    return s;
}

int main() {
    unsigned int n, b;

    for (b=0; b<=100000; ++b) {
        ans[b] = 0;
    }
    ans[1] = 2;
    ans[2] = 3;
    ans[3] = 3;
    ans[4] = 5;
    ans[5] = 8;

    std::cin >> n;
    while (n--) {
        std::cin >> b;
        std::cout << calc(b) << std::endl;
    }
    return 0;
}
