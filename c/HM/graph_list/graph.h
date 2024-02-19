#include <stdio.h>

struct Edge {
    int to;
    int weight;
    struct Edge *next;
}typedef Edge;

struct Vertex {
    int data;
    Edge *edges;
}typedef Vertex;

struct Graph {
    int numVertices;
    Vertex **vertices;
}typedef Graph;

// Initialize graph
Graph* InitGraph(int n);

// Add an edge to the graph
void AddEdge(Graph * graph, int x, int y, int weight);

// Remove an edge from the graph
void RemoveEdge(

Graph * graph  , int x, int y);

// Change the weight of an edge in the graph
void ChangeWeight(Graph * graph, int x, int y, int weight);

// Check if a vertex exists in the graph
int HasVertex(

Graph * graph, int v);

// Check if an edge exists between two existing vertices
int HasEdge(

Graph * graph, int x, int y);

// Add a vertex to the graph
void AddVertex(

Graph * graph , int v);

// Remove a vertex from the graph
void RemoveVertex(

Graph * graph, int v);