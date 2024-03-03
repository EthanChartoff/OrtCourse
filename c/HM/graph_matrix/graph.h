// API of simple, directed and weigthed Graph

# define VERTICES_INIT_BUFFER 100

// Graph
// A simple and weighted Graph.
// 0 means that there is no edge. Weight cannot be 0.
// Vertices values are exclusive (different values)

// adjacency matrix

typedef struct
{
	int **adjacencyMatrix;
	int size; // the max index of the vertices inserted to the Graph
} Graph;

// Interface of our ADT Graph  (API)

void InitGraph(Graph* g);
void AddEdge(Graph g, int from, int to, int weight);
void RemoveEdge(Graph g, int from, int to);
void UpdateEdge(Graph g, int from, int to, int weight);
void AddVertex(Graph* g, int vertex_index);
void RemoveVertex(Graph* g, int vertex_index);
int HasEdge(Graph g, int from, int to);
int HasVertex(Graph g, int vertex_index);
void PrintGraph(Graph g);