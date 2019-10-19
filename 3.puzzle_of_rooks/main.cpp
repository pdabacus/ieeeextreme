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

void print_move(Move* m) {
    printf("%d %d %c\n", m->x, m->y, m->c);
}

int index_of(int* arr, int x) {
    int j = 0;
    while (true) {
        if (*(arr++) == x) {
            return j;
        }
        ++j;
    }
}

#ifdef VERBOSE
void print_board(int n, int posx[], int posy[], int destx[], int desty[]) {
    int a, b, c, d;
    int j, k, j2;
    char color;

    // a < x < b
    // c > y > d
    a = posx[0];
    b = posx[0];
    c = posy[0];
    d = posy[0];
    for (j=0; j<n; ++j) {
        if (posx[j] > b) {
            b = posx[j];
        }
        if (destx[j] > b) {
            b = destx[j];
        }
        if (posx[j] < a) {
            a = posx[j];
        }
        if (destx[j] < a) {
            a = destx[j];
        }
        if (posy[j] > c) {
            c = posy[j];
        }
        if (desty[j] > c) {
            c = desty[j];
        }
        if (posy[j] < d) {
            d = posy[j];
        }
        if (desty[j] < d) {
            d = desty[j];
        }
    }

    for (j=c; j>=d; --j) {
        printf("[");
        for (k=a; k<=b; ++k) {
            color = ' ';
            for (j2=0; j2<n; ++j2) {
                if (posx[j2] == k && posy[j2] == j) {
                    color = 'A' + j2;
                }
                if (destx[j2] == k && desty[j2] == j) {
                    color = '.';
                }
            }
            printf(" %c", color);
        }
        printf(" ]\n");
    }
    printf("(%d,%d)\n", a, d);
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
#endif

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
    int a, b, x, y;

    std::vector<Move> moves;
    std::vector<Move>::iterator mi, mend;
    Move m;

    int pj2, pk2, pj3, pk, pj;
    int disabled = -1;
    int disabledx, disabledy;
    bool obs[10];
    int obsk2[10];

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
        print_board(n, posx, posy, destx, desty);
    #endif

    #ifdef VERBOSE
        printf("moving rooks down\n");
    #endif
    for (j=n-1; j>=0; --j) {
        y = desty[indicesy[j]];
        j2 = indicesy2[j];
        x = posx[j2];
        for (k=posy[j2]; k>y; --k) {
            m = {x, k, 'D'};
            moves.push_back(m);
            --posy[j2];
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
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
        x = posx[j2];
        for (k=posy[j2]; k<y; ++k) {
            m = {x, k, 'U'};
            moves.push_back(m);
            ++posy[j2];
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
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
            if (posx[indices2[k]] > posx[indices2[maxx2]]) {
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

    // set left most rook as pivot
    pj2 = n-1;
    pk2 = indices2[pj2]; // left most x rook pos
    pj3 = index_of(indicesy2, pk2); // y index for left most rook
    pk = indicesy[pj3]; // pos of same height destination
    pj = index_of(indices, pk); // target horizontal position
    for (j=0; j<n; ++j) {
        obs[j] = 0;
        obsk2[j] = -1;
    }

    for (j2=n-2; j2>=0; --j2) {
        k2 = indices2[j2]; // next left most x rook pos
        j3 = index_of(indicesy2, k2); // y index for next left most rook
        k = indicesy[j3]; // pos of same height destination
        j = index_of(indices, k); // x index for same height destination

        // move past pivot
        if (disabled != pj) {
            if (disabled >= 0) {
                // reenable old
                m = {disabledx, disabledy, 'P'};
                moves.push_back(m);
                #ifdef VERBOSE
                    printf("enabling rook %d\n", disabled);
                    print_move(&m);
                    print_board(n, posx, posy, destx, desty);
                #endif
            }
            // disable pivot
            disabled = pj;
            disabledx = posx[pk2];
            disabledy = posy[pk2];
            m = {disabledx, disabledy, 'T'};
            moves.push_back(m);
            #ifdef VERBOSE
                printf("disabling pivot %d\n", pj);
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
        }

        // move next rook past pivot
        x = posx[k2] - posx[pk2] + 1;
        y = posy[k2];
        for (j3=0; j3<x; ++j3) {
            m = {posx[k2]--, y, 'L'};
            moves.push_back(m);
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
        }
        // obs   = [1 1 0 0 1 1 0 0 1 1] if destj has been moved across yet
        // obsk2 = [0 1 - - 2 3 - - 4 5] the k2 for each j

        // move next rook across obstacles
        for (j3=0; j3<j; ++j3) {
            if (obs[j3] && disabled != j3) {
                if (disabled >= 0) {
                    // reenable old
                    m = {disabledx, disabledy, 'P'};
                    moves.push_back(m);
                    #ifdef VERBOSE
                        printf("enabling rook %d\n", disabled);
                        print_move(&m);
                    #endif
                }
                // disable obstacle
                disabled = j3;
                disabledx = posx[obsk2[j3]];
                disabledy = posy[obsk2[j3]];
                m = {disabledx, disabledy, 'T'};
                moves.push_back(m);
                #ifdef VERBOSE
                    printf("disabling obstacle %d\n", j3);
                    print_move(&m);
                #endif
            }

            m = {posx[k2]--, y, 'L'};
            moves.push_back(m);
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
            m = {posx[k2]--, y, 'L'};
            moves.push_back(m);
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
        }

        m = {posx[k2]--, y, 'L'};
        moves.push_back(m);
        #ifdef VERBOSE
            print_move(&m);
            print_board(n, posx, posy, destx, desty);
        #endif

        // add this rook to obstacles
        obs[j] = true;
        obsk2[j] = k2;
        #ifdef VERBOSE
            printf("obs = [ ");
            for (j3=0; j3<n; ++j3) {
                printf("%d ", (int) obs[j3]);
            }
            printf("]\n\n");
        #endif
    }

    // reenable
    if (disabled >= 0) {
        m = {disabledx, disabledy, 'P'};
        moves.push_back(m);
        #ifdef VERBOSE
            printf("enabling rook %d\n", disabled);
            print_move(&m);
        #endif
        disabled = -1;
    }

    // move pivot left to correct place
    y = posy[pk2];
    obsk2[pj] = pk2;

    m = {posx[pk2]--, y, 'L'};
    moves.push_back(m);
    #ifdef VERBOSE
        print_move(&m);
        print_board(n, posx, posy, destx, desty);
    #endif

    // move pivot over all obstacles
    for (j3=0; j3<pj; ++j3) {
        if (obs[j3] && disabled != j3) {
            if (disabled >= 0) {
                // reenable old
                m = {disabledx, disabledy, 'P'};
                moves.push_back(m);
                #ifdef VERBOSE
                    printf("enabling rook %d\n", disabled);
                    print_move(&m);
                #endif
            }
            // disable obstacle
            disabled = j3;
            disabledx = posx[obsk2[j3]];
            disabledy = posy[obsk2[j3]];
            m = {disabledx, disabledy, 'T'};
            moves.push_back(m);
            #ifdef VERBOSE
                printf("disabling obstacle %d\n", j3);
                print_move(&m);
            #endif
        }

        m = {posx[pk2]--, y, 'L'};
        moves.push_back(m);
        #ifdef VERBOSE
            print_move(&m);
            print_board(n, posx, posy, destx, desty);
        #endif
        m = {posx[pk2]--, y, 'L'};
        moves.push_back(m);
        #ifdef VERBOSE
            print_move(&m);
            print_board(n, posx, posy, destx, desty);
        #endif
    }

    // reenable old
    if (disabled >= 0) {
        m = {disabledx, disabledy, 'P'};
        moves.push_back(m);
        #ifdef VERBOSE
            printf("enabling rook %d\n", disabled);
            print_move(&m);
        #endif
        disabled = -1;
    }

    #ifdef VERBOSE
        printf("moving rooks left\n");
    #endif
    for (j=n-1; j>=0; --j) {
        k = indices[j];
        k2 = obsk2[j];
        a = destx[k];
        //b = desty[k];
        x = posx[k2];
        y = posy[k2];
        //printf("(%d,%d)->(%d,%d)\n", x, y, a, b);
        for (j2=x; j2>a; --j2) {
            m = {j2, y, 'L'};
            moves.push_back(m);
            --posx[k2];
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
        }
    }

    #ifdef VERBOSE
        printf("moving rooks right\n");
    #endif
    for (j=0; j<n; ++j) {
        k = indices[j];
        k2 = obsk2[j];
        a = destx[k];
        x = posx[k2];
        y = posy[k2];
        #ifdef VERBOSE
            b = desty[k];
            printf("(%d,%d)->(%d,%d)\n", x, y, a, b);
        #endif
        for (j2=x; j2<a; ++j2) {
            m = {j2, y, 'R'};
            moves.push_back(m);
            ++posx[k2];
            #ifdef VERBOSE
                print_move(&m);
                print_board(n, posx, posy, destx, desty);
            #endif
        }
    }

    #ifdef VERBOSE
        printf("destinations:\n");
        print_pos(n, destx, desty);
        printf("positions:\n");
        print_pos(n, posx, posy);
    #endif


    mend = moves.end();
    printf("%lu\n", moves.size());
    for (mi=moves.begin(); mi!=mend; ++mi) {
        print_move(&*mi);
    }

    return 0;
}
