#include <cstdio>
#include <iostream>

#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int n, a, b;
    unsigned int j;

    std::cin >> n >> a >> b;
    #ifdef VERBOSE
        printf("n=%u, a=%u, b=%u\n", n, a, b);
    #endif
    return 0;
}
