//===-------------------------------------------------------===
//  a simple, weighted and direcred graph, implemented using a matrix.
//  as an example, lets say we want to implement the matrix in the example,
//  we would implement it as:
// 
//      0 1 2 3
//    ----------
//  0 | 0 8 7 0
//  1 | 0 0 3 29
//  2 | 0 0 0 0
//  3 | 0 0 1 0 
//
//===-------------------------------------------------------===

typedef struct SIMPLE_WEIGHTED_DIRECTED_GRAPH_STRUCT {
    int **graph;
    unsigned int length;
    unsigned int n_vetex;
    unsigned int n_edeges;
} swd_graph;

swd_graph* init();
void has_vertice(int v);
void add_vertice(int v);
void remove_vertice(int v);
void has_edge(int e);
void add_edge(int src, int dest, int weight);
void remove_edge(int src, int dest);
void change_weight(int src, int dest, int weight);
