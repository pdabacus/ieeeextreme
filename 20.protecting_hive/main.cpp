#include <cstdio>
#include <iostream>
#include <vector>

#define VERBOSE

#ifdef VERBOSE
void print_hive(int N, int M, bool** hive) {
    int j, k, m;
    for (j=0; j<N; ++j) {
        m = M - (j % 2);
        printf("[ ");
        if (j % 2 == 1) {
            printf("  ");
        }
        for (k=0; k<m; ++k) {
            printf("%2d  ", hive[j][k]);
        }
        if (j % 2 == 1) {
            printf("  ");
        }
        printf("]\n");
    }
}
#endif

int main(int argc, char* argv[]) {
    int N, M;
    int j, k, m;

    std::cin >> N >> M;
    #ifdef VERBOSE
        printf("N=%u, M=%u\n", N, M);
    #endif

    bool** hive = new bool*[N];
    for (j=0; j<N; ++j) {
        m = M - (j % 2);
        hive[j] = new bool[m];
        for (k=0; k<m; ++k) {
            std::cin >> hive[j][k];
        }
    }
    #ifdef VERBOSE
        print_hive(N, M, hive);
    #endif

    // free heap
    for (j=0; j<N; ++j) {
        delete[] hive[j];
    }
    delete[] hive;

    return 0;
}
