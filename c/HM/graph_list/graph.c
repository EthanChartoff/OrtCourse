#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


static int findVertex(Graph g, int data) {
    int i;

    for(i = 0; i < g.numVertices; ++i) {
        if(g.vertices[i]->data == data)
            return i;
    }

    return -1;
}

void InitGraph(Graph* g) {
    g = (Graph *)malloc(sizeof(Graph));
    if(g == NULL) {
        printf("error allocating data to graph");
        exit(EXIT_FAILURE);
    }
    g->numVertices = 0;
    g->vertices = malloc(sizeof(Vertex) * sizeof(g->numVertices));
}


void AddEdge(Graph g, int from, int to, int weight) {
    if(!(HasVertex(g, from) && HasVertex(g, to)))
        return;
    
    int from_index = findVertex(g, from);
    // Create a new edge
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = g.vertices[from_index]->edges;

    // Add the edge to the source vertex's edge list
    g.vertices[from_index]->edges = newEdge;
}

void RemoveEdge(Graph g, int from, int to) {
    // Ensure vertices exist
    if (!(HasVertex(g, from) && HasVertex(g, to)))
        return;

    // Traverse the edge list of the source vertex
    Edge *prev = NULL;
    int from_index = findVertex(g, from);
    Edge *curr = g.vertices[from_index]->edges;
    while (curr) {
        if (curr->to == to) {
            // Found the edge, remove it
            if (prev) {
                prev->next = curr->next;
            } else {
                g.vertices[from_index]->edges = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // Edge not found
}

void UpdateEdge(Graph g, int from, int to, int weight) {
    // Ensure vertices exist and edge exists
    if (!(HasVertex(g, from) && HasVertex(g, to) && HasEdge(g, from, to)))
        return;

    // Traverse the edge list of the source vertex
    Edge *curr = g.vertices[findVertex(g, from)]->edges;
    while (curr) {
        if (curr->to == to) {
            curr->weight = weight;
            return;
        }
        curr = curr->next;
    }
}

void AddVertex(Graph* g, int data) {
// Check if vertex already exists
    if (HasVertex(*g, data)) {
        printf("Vertex already exists!\n");
        return;
    }

    // Increase the number of vertices and reallocate memory
    g->numVertices++;
    g->vertices = (Vertex **)realloc(g->vertices, g->numVertices * sizeof(Vertex *));

    // Create a new vertex and add it to the graph
    g->vertices[g->numVertices - 1] = (Vertex *)malloc(sizeof(Vertex));
    g->vertices[g->numVertices - 1]->data = data;
    g->vertices[g->numVertices - 1]->edges = NULL;
}

void RemoveVertex(Graph* g, int data) {
    int i;

    if(!HasVertex(*g, data))  
        return;
    
    // Remove all edges incident to the vertex
    for (int i = 0; i < g->numVertices; i++) {
        RemoveEdge(*g, data, g->vertices[i]->data);  // Remove edges in both directions
        RemoveEdge(*g, g->vertices[i]->data, data);
    }

    // Free the vertex
    int data_index=findVertex(*g, data);
    free(g->vertices[data_index]);

    // Shift vertices to the left to fill the gap
    for (i = data_index; i < g->numVertices - 1; i++) {
        g->vertices[i] = g->vertices[i + 1];
    }

    // Decrease the number of vertices and reallocate memory
    g->numVertices--;
    g->vertices = (Vertex**)realloc(g->vertices, g->numVertices * sizeof(Vertex*));
}

int HasVertex(Graph g, int data) {
    return findVertex(g, data) != -1;
}

int HasEdge(Graph g, int from, int to) {
    // Ensure vertices exist
    if (!(HasVertex(g, from) && HasVertex(g, to))) {
        return 0;
    }

    // Traverse the edge list of the source vertex
    Edge *curr = g.vertices[findVertex(g, from)]->edges;
    while (curr) {
        if (curr->to == to) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void PrintGraph(Graph g) {
    int i;
    
    for (i = 0; i < g.numVertices; i++) {
        printf("  - Vertex %d:", g.vertices[i]->data);
        Edge *curr = g.vertices[i]->edges;
        if (!curr) {
            printf(" (no edges)\n");
            continue;
        }
        
        printf(" ");
        while (curr) {
            printf("%d (weight: %d) ", curr->to, curr->weight);
            curr = curr->next;
        }
        printf("\n");
    }
}
