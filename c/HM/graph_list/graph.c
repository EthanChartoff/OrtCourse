#include "graph.h"
#include <stdlib.h>

Graph* InitGraph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->vertices = (Vertex **)malloc(n * sizeof(Vertex *));
    for (int i = 0; i < n; i++) {
        graph->vertices[i] = (Vertex *)malloc(sizeof(Vertex));
        graph->vertices[i]->data = i;
        graph->vertices[i]->edges = NULL;
    }
    return graph;
}


void AddEdge(Graph *graph, int x, int y, int weight) {
    // Ensure vertices exist
    if (x >= graph->numVertices || y >= graph->numVertices) {
        printf("Invalid vertex!\n");
        return;
    }

    // Create a new edge
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = y;
    newEdge->weight = weight;
    newEdge->next = graph->vertices[x]->edges;

    // Add the edge to the source vertex's edge list
    graph->vertices[x]->edges = newEdge;
}

void RemoveEdge(Graph *graph, int x, int y) {
    // Ensure vertices exist
    if (x >= graph->numVertices || y >= graph->numVertices) {
        printf("Invalid vertex!\n");
        return;
    }

    // Traverse the edge list of the source vertex
    Edge *prev = NULL;
    Edge *curr = graph->vertices[x]->edges;
    while (curr) {
        if (curr->to == y) {
            // Found the edge, remove it
            if (prev) {
                prev->next = curr->next;
            } else {
                graph->vertices[x]->edges = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // Edge not found
    printf("Edge not found!\n");
}

void ChangeWeight(Graph *graph, int x, int y, int weight) {
    // Ensure vertices exist and edge exists
    if (x >= graph->numVertices || y >= graph->numVertices || !HasEdge(graph, x, y)) {
        printf("Invalid vertex or edge!\n");
        return;
    }

    // Traverse the edge list of the source vertex
    Edge *curr = graph->vertices[x]->edges;
    while (curr) {
        if (curr->to == y) {
            curr->weight = weight;
            return;
        }
        curr = curr->next;
    }
}

int HasVertex(Graph *graph, int v) {
    return v >= 0 && v < graph->numVertices;
}

int HasEdge(Graph *graph, int x, int y) {
    // Ensure vertices exist
    if (x >= graph->numVertices || y >= graph->numVertices) {
        return 0;
    }

    // Traverse the edge list of the source vertex
    Edge *curr = graph->vertices[x]->edges;
    while (curr) {
        if (curr->to == y) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void AddVertex(Graph *graph, int v) {
    // Check if vertex already exists
    if (HasVertex(graph, v)) {
        printf("Vertex already exists!\n");
        return;
    }

    // Increase the number of vertices and reallocate memory
    graph->numVertices++;
    graph->vertices = (Vertex **)realloc(graph->vertices, graph->numVertices * sizeof(Vertex *));

    // Create a new vertex and add it to the graph
    graph->vertices[graph->numVertices - 1] = (Vertex *)malloc(sizeof(Vertex));
    graph->vertices[graph->numVertices - 1]->data = v;
    graph->vertices[graph->numVertices - 1]->edges = NULL;
}