#include <cstdio>
#include <iostream>

//#define VERBOSE

typedef struct node {
    long int x;
    struct node* l;
    struct node* r;
} Node ;

#ifdef VERBOSE
void print_tree(Node* t) {
    if (t->l != NULL) {
        print_tree(t->l);
    }
    printf(" * %ld\n", t->x);
    if (t->r != NULL) {
        print_tree(t->r);
    }
}
#endif

unsigned int insert(Node* root, long int x) {
    Node* ins;
    if (x <= root->x) {
        if (root->l == NULL) {
            ins = new Node;
            ins->x = x;
            ins->l = NULL;
            ins->r = NULL;
            root->l = ins;
            return 1;
        } else {
            return 1 + insert(root->l, x);
        }
    } else {
        if (root->r == NULL) {
            ins = new Node;
            ins->x = x;
            ins->l = NULL;
            ins->r = NULL;
            root->r = ins;
            return 1;
        } else {
            return 1 + insert(root->r, x);
        }
    }
}

int main(int argc, char* argv[]) {
    unsigned int N, j;
    long int x;
    std::cin >> N;
    std::cin >> x;
    Node root = {x, NULL, NULL};
    printf("1\n");
    #ifdef VERBOSE
        print_tree(&root);
        printf("\n");
    #endif
    for (j=1; j<N; ++j) {
        std::cin >> x;
        printf("%d\n", 1+ insert(&root, x));
        #ifdef VERBOSE
            print_tree(&root);
            printf("\n");
        #endif
    }

    return 0;
}
