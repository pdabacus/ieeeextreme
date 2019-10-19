#include <cstdio>
#include <iostream>

//#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int n;

    std::cin >> n;
    #ifdef VERBOSE
        printf("n=%u\n", n);
    #endif


    return 0;
}
