#include <cstdio>
#include <iostream>
#include <vector>

#define VERBOSE

//Move m = {1, 2, 'A'};
//print_move(&m);
typedef struct {
    int x;
    int y;
    char c;
} Move;

int index_of(int* arr, int x) {
    int j = 0;
    while (true) {
        if (*(arr++) == x) {
            return j;
        }
        ++j;
    }
}

void print_move(Move* m) {
    printf("%d %d %c\n", m->x, m->y, m->c);
}

void print_arr(int n, int arr[]) {
    int j;
    printf("[ ");
    for (j=0; j<n; ++j) {
        printf("%d ", arr[j]);
    }
    printf("]\n");
}

void print_pos(int n, int posx[], int posy[]) {
    int j;
    for (j=0; j<n; ++j) {
        printf("  (%d,%d)\n", posx[j], posy[j]);
    }
}

int main(int argc, char* argv[]) {
    int n;
    int j, k, j2, k2, j3;
    int destx[10];
    int desty[10];
    int posx[10];
    int posy[10];

    int indices[10];
    int indices2[10];
    int indicesy[10];
    int indicesy2[10];
    int maxy, maxy2, maxx, maxx2;
    int a, b;
    int x, x2, y;

    std::vector<Move> moves;
    std::vector<Move>::iterator i, end;
    Move m;

    std::vector<int> obs;
    std::vector<int> obs2;

    std::cin >> n;
    #ifdef VERBOSE
        printf("n=%d\n", n);
    #endif

    for (j=0; j<n; ++j) {
        std::cin >> posx[j];
        std::cin >> posy[j];
    }

    for (j=0; j<n; ++j) {
        std::cin >> destx[j];
        std::cin >> desty[j];
    }

    #ifdef VERBOSE
        printf("destinations:\n");
        print_pos(n, destx, desty);
        printf("positions:\n");
        print_pos(n, posx, posy);
    #endif

    // indicesy = [0, 1, 2, ..., 9]
    for (j=0; j<n; ++j) {
        indicesy[j] = j;
        indicesy2[j] = j;
    }

    // indices = [a, b, c, ... f] so that desty[a] > desty[b] > ...
    for (j=0; j<n-1; ++j) {
        maxy = j;
        maxy2 = j;
        for (k=j+1; k<n; ++k) {
            if (desty[indicesy[k]] > desty[indicesy[maxy]]) {
                maxy = k;
            }
            if (posy[indicesy2[k]] > posy[indicesy2[maxy]]) {
                maxy2 = k;
            }
        }
        a = indicesy[j];
        b = indicesy2[j];
        indicesy[j] = indicesy[maxy];
        indicesy2[j] = indicesy2[maxy2];
        indicesy[maxy] = a;
        indicesy2[maxy2] = b;
    }
    #ifdef VERBOSE
        printf("destinations y order: ");
        print_arr(n, indicesy);
        printf("positions y order: ");
        print_arr(n, indicesy2);
    #endif

    #ifdef VERBOSE
        printf("moving rooks down\n");
    #endif
    for (j=n-1; j>=0; --j) {
        y = desty[indicesy[j]];
        j2 = indicesy2[j];
        x2 = posx[j2];
        for (k=posy[j2]; k>y; --k) {
            m = {x2, k, 'D'};
            #ifdef VERBOSE
                print_move(&m);
            #endif
            moves.push_back(m);
            --posy[j2];
        }
        #ifdef VERBOSE
            printf("\n");
        #endif
    }

    #ifdef VERBOSE
        printf("moving rooks up\n");
    #endif
    for (j=0; j<n; ++j) {
        y = desty[indicesy[j]];
        j2 = indicesy2[j];
        x2 = posx[j2];
        for (k=posy[j2]; k<y; ++k) {
            m = {x2, k, 'U'};
            #ifdef VERBOSE
                print_move(&m);
            #endif
            moves.push_back(m);
            ++posy[j2];
        }
        #ifdef VERBOSE
            printf("\n");
        #endif
    }

    #ifdef VERBOSE
        printf("destinations:\n");
        print_pos(n, destx, desty);
        printf("positions:\n");
        print_pos(n, posx, posy);
    #endif

    // indices = [0, 1, 2, ..., 9]
    for (j=0; j<n; ++j) {
        indices[j] = j;
        indices2[j] = j;
    }

    // indices = [a, b, c, ... f] so that destx[a] > destx[b] > ...
    for (j=0; j<n-1; ++j) {
        maxx = j;
        maxx2 = j;
        for (k=j+1; k<n; ++k) {
            if (destx[indices[k]] > destx[indices[maxx]]) {
                maxx = k;
            }
            if (posx[indices2[k]] > posx[indices2[maxx]]) {
                maxx2 = k;
            }
        }
        a = indices[j];
        b = indices2[j];
        indices[j] = indices[maxx];
        indices2[j] = indices2[maxx2];
        indices[maxx] = a;
        indices2[maxx2] = b;
    }
    #ifdef VERBOSE
        printf("destinations x order: ");
        print_arr(n, indices);
        printf("positions x order: ");
        print_arr(n, indices2);
    #endif

    #ifdef VERBOSE
        printf("\nleft right mapping:\n");
    #endif

    // pairwise swaps left to right to get right order
    #ifdef VERBOSE
        for (j2=n-1; j2>=0; --j2) {
            k2 = indices2[j2]; // left most x rook pos
            j3 = index_of(indicesy2, k2); // y index for left most rook
            k = indicesy[j3]; // pos of same height destination
            j = index_of(indices, k); // x index for same height destination
            printf("  %d->%d: dst=(%d,%d) rook=(%d,%d)\n", n-j2, n-j,
                destx[k], desty[k], posx[k2], posy[k2]
            );
        }
        printf("\n");
    #endif

    // set first obstacle as left most index
    obs2.push_back(n-1); // j2 = n-1 = current horizontal position
    k2 = indices2[n-1]; // left most x rook pos
    j3 = index_of(indicesy2, k2); // y index for left most rook
    k = indicesy[j3]; // pos of same height destination
    j = index_of(indices, k); // target horizontal position
    obs.push_back(j);

    for (j2=n-2; j2>=0; --j2) {
        k2 = indices2[j2]; // next left most x rook pos
        j3 = index_of(indicesy2, k2); // y index for next left most rook
        k = indicesy[j3]; // pos of same height destination
        j = index_of(indices, k); // x index for same height destination

        a = 0;
        end = obs.end();
        for (i=obs.begin(); i!=end; ++i) {
            if
        }
        //printf("  %d->%d: dst=(%d,%d) rook=(%d,%d)\n", n-j2, n-j,
        //    destx[k], desty[k], posx[k2], posy[k2]
        //);

        //printf("  piv=%d, rookx=%d, lefts=%d+2*%d=%d\n", n-pj, n-j,
        //    posx[k2]-posx[pk2], j-pj, posx[k2]-posx[pk2] + 2*(j-pj)
        //);
    }

    //end = moves.end();
    //for (i=moves.begin(); i!=end; ++i) {
    //    print_move(&*i);
    //}

    return 0;
}
