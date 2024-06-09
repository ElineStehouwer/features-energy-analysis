#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "avl-tree.h"
#include <gc/gc.h>


#define malloc(x) GC_MALLOC(x)
#define calloc(n,x) GC_MALLOC((n)*(x))
#define realloc(p,x) GC_REALLOC((p),(x))
#define free(x) (x) = NULL

#define MAX_KEY_VALUE 1000

typedef struct NodeData {
    int    key;
    double value;
} *NodeData;

int comp (void *a1, void *a2) {
    NodeData nd1 = (NodeData) a1;
    NodeData nd2 = (NodeData) a2;

    if (nd1->key < nd2->key) {
        return -1;
    } else if (nd1->key > nd2->key) {
        return +1;
    } else {
        return 0;
    }
}

void print (void *a) {
    NodeData nd = (NodeData) a;

    printf ("%3d \"%6.3f\"", nd->key, nd->value);
}

void main_function() {
    Tree tree;
    Node node;
    NodeData nd1 = NULL, nd2;

    tree = Tree_New (comp, print);
    int no_to_to = 0;
    while (no_to_to < 20000) {
        if (nd1 == NULL) {
            nd1 = malloc (sizeof (*nd1));
        }
        nd1->key = rand () % MAX_KEY_VALUE;
        nd1->value = sqrt (nd1->key);
        if ((node = Tree_SearchNode (tree, nd1)) != NULL) {
            // printf (">>> delete key %d\n\n", nd1->key);
            nd2 = Node_GetData (node);
            Tree_DeleteNode (tree, node);
            free (nd2);
        } else {
            // printf (">>> insert key %d\n\n", nd1->key);
            Tree_Insert (tree, nd1);
            nd1 = NULL;
        }
        // Tree_Print (tree);
        no_to_to++;
    }
}

int main (void) {
    for (int i = 0; i < 1; i++){//7500
        main_function();
    }

    return 0;
}
