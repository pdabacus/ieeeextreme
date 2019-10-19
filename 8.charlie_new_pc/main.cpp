#include <cstdio>
#include <iostream>

#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int T, N;
    unsigned int j, k, n, m;
    unsigned long int B;
    unsigned long int x;
    unsigned int Ns[10];
    unsigned int Nj;
    unsigned int* Ks[10];
    unsigned int* Kj;

    // repeat T times
    std::cin >> T;
    while (T--) {
        // total sum and num of rows in this test
        std::cin >> B >> N;
        #ifdef VERBOSE
            printf("B=%lu, N=%d x [", B, N);
        #endif

        // get length of each row
        for (j=0; j<N; ++j) {
            std::cin >> k;
            #ifdef VERBOSE
                printf(" %d", k);
            #endif
            Ns[j] = k;
            Ks[j] = new unsigned int[k+1];
        }
        #ifdef VERBOSE
            printf(" ]\n");
        #endif

        // read each element and insert sort
        for (j=0; j<N; ++j) {
            Kj = Ks[j];
            Nj = Ns[j];
            for (k=0; k<Nj; ++k) {
                std::cin >> x;
                for (n=0; n<k; ++n) {
                    if (x > Kj[n]) {
                        break;
                    }
                }
                for (m=k; m>n; --m) {
                    Kj[m] = Kj[m-1];
                }
                Kj[m] = x;
            }
        }
        Kj[Nj] = 0;

        // print sorted rows
        #ifdef VERBOSE
            for (j=0; j<N; ++j) {
                printf(" * ");
                Nj = Ns[j];
                for (k=0; k<=Nj; ++k) {
                    printf("%2d  ", Ks[j][k]);
                }
                printf("\n");
            }
        #endif
    }

    for (j=0; j<N; ++j) {
        delete[] Ks[j];
    }

    return 0;
}
