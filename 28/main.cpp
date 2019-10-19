#include <cstdio>
#include <iostream>

#define VERBOSE

int main() {
    unsigned int n;
    std::cin >> n;
    #ifdef VERBOSE
        printf("n=%d\n", n);
    #endif

    while (n--) {
    }
    return 0;
}
