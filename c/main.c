#include "HM/graph_matrix/graph.h"
#include <stdio.h>

int main(void) {
    int **g, i, j;
    g = initGraph(3);

    addVertix(&g, 2);
    addVertix(&g, 4);    

    addEdge(&g, 2, 4, 6);
    print_graph(g);

    return 0;
}