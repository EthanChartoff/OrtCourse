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

// Interface of our ADT Graph  (API)
void InitGraph(Graph* g);
void AddEdge(Graph g, int from, int to, int weight);
void RemoveEdge(Graph g, int from, int to);
void UpdateEdge(Graph g, int from, int to, int weight);
void AddVertex(Graph* g, int data);
void RemoveVertex(Graph* g, int data);
int  HasEdge(Graph g, int from, int to);
int  HasVertex(Graph g, int data);
void PrintGraph(Graph g);