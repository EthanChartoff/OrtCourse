//===-------------------------------------------------------===
//  a simple, weighted and direcred graph, implemented using a matrix.
//  as an example, lets say we want to implement the matrix in the example,
//  we would implement it as:
// 
//      0 1 2 3
//    ----------
//  0 | 1 8 7 0
//  1 | 0 1 3 29
//  2 | 0 0 1 0
//  3 | 0 0 1 1 
//
// the 1s in the main diagonal symbols that the vertice exists.
// note: can only make one graph, because you cant save the length
//       of the graph with thie implementation.
//===-------------------------------------------------------===


// Function to create a matrix
int ** initGraph(int n);

// Function to check if a vertix exists in the graph
int hasVertix(int **mat, int v);

// Function to check if an edge exists between two vertices
int hasEdge(int **mat, int x, int y);

// Function to add an edge to the graph
void addEdge(int ***mat, int x, int y, int cost);

// Function to remove an edge from the graph
void removeEdge(int ***mat, int x, int y);

// Function to add a vertix to the graph
void addVertix(int ***mat, int n);

// Function to remove a vertix from the graph
void removeVertix(int ***mat, int n, int v);

// Function to change the weight of an edge in the graph
void changeWeight(int ***mat, int x, int y, int cost);

void print_graph(int **mat);