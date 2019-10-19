#include <cstdio>
#include <iostream>
#include <vector>

#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int N, M;
    unsigned int x;
    std::vector<unsigned int> A, S;
    std::vector<unsigned int>::iterator i, end;
    unsigned int j;

    std::cin >> N >> M;
    #ifdef VERBOSE
        printf("N=%u, M=%u\n", N, M);
    #endif

    // build A
    for (j=0; j<N; ++j) {
        std::cin >> x;
        A.push_back(x);
    }

    #ifdef VERBOSE
        end = A.end();
        printf("A = [ ");
        for (i=A.begin(); i!=end; ++i) {
            printf("%u ", *i);
        }
        printf("]\n");
    #endif

    // build S sorted small to large
    std::cin >> x;
    S.push_back(x);
    for (j=1; j<M; ++j) {
        std::cin >> x;
        end = S.end();
        for (i=S.begin(); i!=end; ++i) {
            if (*i > x) {
                S.insert(i, x);
                break;
            }
        }
    }

    #ifdef VERBOSE
        end = S.end();
        printf("S = [ ");
        for (i=S.begin(); i!=end; ++i) {
            printf("%u ", *i);
        }
        printf("]\n");
    #endif

    return 0;
}
