#include "directed_weighted_simple_graph.h"
#include <stdio.h>
#include <stdlib.h>

swd_graph* init() {
    swd_graph *g = (swd_graph*) malloc(sizeof(swd_graph));

    printf("%d", g->graph[0][0]);
}