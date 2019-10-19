#include <cstdio>
#include <iostream>

//#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned long int N, a, b; // target num
    unsigned long int n;
    unsigned long int max_len;
    unsigned long int min, max;
    unsigned long int left;
    unsigned long int num_b;
    unsigned long int k;

    std::cin >> N >> a >> b;
    #ifdef VERBOSE
        printf("N=%lu, a=%lu, b=%lu\n", N, a, b);
    #endif

    max_len = N / a;
    for (n=N/b; n<=max_len; ++n) {
        min = n * a;
        max = n * b;
        #ifdef VERBOSE
            printf("trying length %lu: %lu <= N <= %lu\n", n, min, max);
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
                printf("num_b=%lu, left=%lu\n", num_b, left);
            #endif
            for (k=0; k<n-num_b-1; ++k) {
                printf("%lu ", a);
            }
            printf("%lu ", a + left);
            for (k=0; k<num_b; ++k) {
                printf("%lu ", b);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
