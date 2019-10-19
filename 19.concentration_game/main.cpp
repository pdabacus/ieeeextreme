#include <cstdio>
#include <iostream>
#include <map>
#include <string>

//#define VERBOSE

int ans[] = {0, 3, 4, 3, 4, 1, 2, 5, 5, 1, 2};
const char* sim(int a, int b) {
    char* resp = new char[16];
    if (ans[a] == ans[b]) {
        sprintf(resp, "MATCH\n");
    } else {
        sprintf(resp, "%d %d\n", ans[a], ans[b]);
    }
    return resp;
}

int main(int argc, char* argv[]) {
    int N, L;
    int j, k;
    int* a;
    int x, y;
    std::map<int,int> seen;
    const char* resp;
    std::string str;


    std::cin >> N;
    L = 2*N;
    #ifdef VERBOSE
        printf("N=%d\n", N);
    #endif

    int cards[L+1];
    cards[0] = 0;
    for (j=1; j<=L; ++j) {
        cards[j] = -1;
    }

    // cheat first values
    if (false) {
        for (j=3; j<8; ++j) {
            cards[j] = ans[j];
        }
    }

    while (true) {
        y = 0;
        // search for pairs
        for (j=1; j<=L; ++j) {
            if (cards[j] > 0) {
                a = &seen[cards[j]];
                #ifdef VERBOSE
                    printf(" * seen[%d] = %d\n", cards[j], *a);
                #endif
                if (*a > 0) {
                    // found pair
                    x = *a;
                    y = j;
                    #ifdef VERBOSE
                        printf("pair cards[%d]=%d, cards[%d]=%d\n",
                            x, cards[x], y, cards[y]
                        );
                    #endif
                    break;
                } else {
                    *a = j;
                }
            }
        }
        seen.clear();

        // search for unknowns
        if (y == 0) {
            x = 0;
            for (j=1; j<=L; ++j) {
                if (cards[j] < 0) {
                    if (x == 0) {
                        x = j;
                    } else {
                        y = j;
                        #ifdef VERBOSE
                            printf("pair unknowns cards[%d]=%d, cards[%d]=%d\n",
                                x, cards[x], y, cards[y]
                            );
                        #endif
                        break;
                    }
                }
            }
        }

        if (y == 0) {
            for (j=1; j<=L; ++j) {
                if (cards[j] > 0) {
                    y = j;
                    #ifdef VERBOSE
                        printf("mixed cards[%d]=%d, cards[%d]=%d\n",
                            x, cards[x], y, cards[y]
                        );
                    #endif
                    break;
                }
            }
        }

        if (y == 0 && x == 0) {
            printf("-1\n");
            return 0;
        }

        std::cout << x << " " << y << std::endl;
        std::cout.flush();

        std::cin >> str;
        if (str[0] == 'M') {
            cards[x] = 0;
            cards[y] = 0;
        } else if (str[0] == '-') {
            return 0;
        } else {
            if (1 != sscanf(str.c_str(), "%d", &j)) {
                printf("real bad\n");
                return 0;
            } else {
                std::cin >> k;
                cards[x] = j;
                cards[y] = k;
            }
        }

        //delete resp;

        printf("[ ");
        for (j=1; j<=L; ++j) {
            printf("%d ", cards[j]);
        }
        printf("]\n\n");
    }

    return 0;
}

