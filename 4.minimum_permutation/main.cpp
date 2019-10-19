#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

//#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int N, M;
    unsigned int x;
    unsigned int j;
    std::vector<unsigned int> A;
    std::vector<unsigned int>::iterator i, end;
    std::priority_queue<
        unsigned int,
        std::vector<unsigned int>,
        std::greater<unsigned int>
    > S;

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

    // build S priority queue
    for (j=0; j<M; ++j) {
        std::cin >> x;
        S.push(x);
    }

    #ifdef VERBOSE
        printf("S top = %u\n", S.top());
    #endif

    // print 2 vectors in taking from next smallest int
    i = A.begin();
    end = A.end();
    while (i != end && !S.empty()) {
        x = S.top();
        if (x < *i) { // s smaller than a
            printf("%u ", x);
            S.pop();
        } else {
            printf("%u ", *(i++));
        }
    }

    for (; i!=end; ++i) {
        printf("%u ", *i);
    }

    while (!S.empty()) {
        printf("%u ", S.top());
        S.pop();
    }
    printf("\n");

    return 0;
}
