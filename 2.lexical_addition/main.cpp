#include <cstdio>
#include <iostream>

//#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int N, a, b; // target num
    unsigned int n;
    unsigned int max_len;
    unsigned int min, max;
    unsigned int left;
    unsigned int num_b;
    unsigned int k;

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
            left = N - min;
            num_b = left/(b-a);
            left -= (b-a)*num_b;
            // (n - num_b - 1) a's
            // left + a
            // (num_b) b's
            #ifdef VERBOSE
                printf("num_b=%u, left=%u\n", num_b, left);
            #endif
            for (k=0; k<n-num_b-1; ++k) {
                printf("%u ", a);
            }
            printf("%u ", a + left);
            for (k=0; k<num_b; ++k) {
                printf("%u ", b);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
