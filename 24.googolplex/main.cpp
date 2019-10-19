#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

//#define VERBOSE

int main(int argc, char* argv[]) {
    unsigned int N, X, Y;
    unsigned long int x, y;
    unsigned int j;
    std::map<unsigned long int, unsigned int> hit;
    std::map<unsigned long int, unsigned int>::iterator i;
    std::vector<unsigned long int> list;
    std::vector<unsigned long int>::iterator i2, end;
    list.reserve(120000);
    unsigned long int minx;

    std::cin >> N;
    while (N--) {
        std::cin >> X >> Y;
        #ifdef VERBOSE
            //t = min_T X^g+T mod 10^Y
            printf("X=%u, Y=%u\n", X, Y);
        #endif

        y = 10;
        for (j=2; j<=Y; ++j) {
            y *= 10;
        }
        x = X = X % y;
        list.push_back(x);
        hit[x] = 0;

        #ifdef VERBOSE
            printf("x = %lu\n", x);
            printf("y = %u\n", y);
        #endif
        for (j=1; j<120000; ++j) {
            x = (x * X) % y;
            //printf("%u: %u\n", j, x);
            i = hit.find(x);
            if (i == hit.end()) {
                hit[x] = j;
                list.push_back(x);
            } else {
                Y = i->second;
                #ifdef VERBOSE
                    printf("j=%u, rep=%u\n", j, Y);
                #endif
                X = 0;
                break;
            }
        }
        if (X > 0) {
            Y = 0;
        }

        i2 = list.begin();
        for (j=0; j<Y; ++j) {
            ++i2;
        }

        minx = *i2;
        end = list.end();
        for (; i2!=end; ++i2) {
            if (*i2 < minx) {
                minx = *i2;
            }
        }
        printf("%lu\n", minx);
        hit.clear();
        list.clear();
    }
    return 0;
}

