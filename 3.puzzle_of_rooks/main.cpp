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
    int j, k, j2, k2;
    int destx[10];
    int desty[10];
    int posx[10];
    int posy[10];
    int toggle = -1;

    int indices[10];
    int indices2[10];
    int maxy;
    int maxy2;
    int a, b;
    int x, x2, y, y2;

    std::vector<Move> moves;
    std::vector<Move>::iterator movej, end;
    Move m;

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
        for (j=0; j<n; ++j) {
            printf("  (%d,%d)\n", destx[j], desty[j]);
        }
        printf("positions:\n");
        print_pos(n, posx, posy);
    #endif

    // indices = [0, 1, 2, ..., 9]
    for (j=0; j<n; ++j) {
        indices[j] = j;
        indices2[j] = j;
    }

    // indices = [a, b, c, ... f] so that desty[a] > desty[b] > ...
    for (j=0; j<n-1; ++j) {
        maxy = j;
        maxy2 = j;
        for (k=j+1; k<n; ++k) {
            if (desty[indices[k]] > desty[indices[maxy]]) {
                maxy = k;
            }
            if (posy[indices2[k]] > posy[indices2[maxy]]) {
                maxy2 = k;
            }
        }
        a = indices[j];
        b = indices2[j];
        indices[j] = indices[maxy];
        indices2[j] = indices2[maxy2];
        indices[maxy] = a;
        indices2[maxy2] = b;
    }
    #ifdef VERBOSE
        printf("destinations y order: ");
        print_arr(n, indices);
        printf("positions y order: ");
        print_arr(n, indices2);
    #endif

    #ifdef VERBOSE
        printf("moving rooks down\n");
    #endif
    for (j=n-1; j>=0; --j) {
        y = desty[indices[j]];
        j2 = indices2[j];
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
        y = desty[indices[j]];
        j2 = indices2[j];
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

    //end = moves.end();
    //for (movej=moves.begin(); movej!=end; ++movej) {
    //    print_move(&*movej);
    //}

    return 0;
}
