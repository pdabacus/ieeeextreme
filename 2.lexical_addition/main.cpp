#include <cstdio>
#include <iostream>

#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int N, a, b; // target num
    unsigned int n;
    unsigned int max_len;
    unsigned int min, max;

    std::cin >> N >> a >> b;
    #ifdef VERBOSE
        printf("N=%u, a=%u, b=%u\n", N, a, b);
    #endif

    max_len = N / a;
    for (n=1; n<=max_len; ++n) {
        min = n * a;
        max = n * b;
        #ifdef VERBOSE
            printf("trying length %u: %u <= N <= %u\n", n, min, max);
        #endif
        if (min <= N && N <= max) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
