#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void InitGraph(Graph* g) {
    g = (Graph *)malloc(sizeof(Graph));
    if(g == NULL) {
        printf("failed to alloc data to *mat\n");
        exit(EXIT_FAILURE);
    }
}
 
int HasVertex(Graph g, int vertex_index) {
    return vertex_index < g.size 
            && g.adjacencyMatrix[vertex_index][vertex_index] != 0;
}

int HasEdge(Graph g, int from, int to) {
    return !!g.adjacencyMatrix[from][to];
}

void AddEdge(Graph g, int from, int to, int weight) {
    if(HasVertex(g, from) && HasVertex(g, to))
        g.adjacencyMatrix[from][to] = weight;
}

void RemoveEdge(Graph g, int from, int to) {
    g.adjacencyMatrix[from][to] = 0;
}

void UpdateEdge(Graph g, int from, int to, int weight) {
    if(HasVertex(g, from) && HasVertex(g, to))
        g.adjacencyMatrix[from][to] = weight;
}

void AddVertex(Graph* g, int vertex_index) {
    int i, j, prev_len, **tmp_mat;

    if(HasVertex(*g, vertex_index))
        return;
    else if(vertex_index < g->size) {
        g->adjacencyMatrix[vertex_index][vertex_index] = 1;
        return;
    }
    
    prev_len = g->size;
    g->size = vertex_index + 1;

    tmp_mat = (int **)malloc(g->size * sizeof(int *));
    if(tmp_mat == NULL && g->size != 0  ) {
        printf("failed to alloc data to *mat\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < g->size; ++i) {
        tmp_mat[i] = (int *)calloc(g->size, sizeof(int));
        if(tmp_mat[i] == NULL && g->size != 0) {
            printf("failed to alloc data to *mat\n");
            exit(EXIT_FAILURE);
        }
        for(j = 0; j < g->size; ++j) {
            if(i < prev_len && j < prev_len) {
                tmp_mat[i][j] = g->adjacencyMatrix[i][j];
            } 
        }
    }

    for(i = 0; i < prev_len; ++i)
        free((g->adjacencyMatrix)[i]);
    free(g->adjacencyMatrix);

    g->adjacencyMatrix = tmp_mat;

    g->adjacencyMatrix[vertex_index][vertex_index] = 1;
    return;
}

void RemoveVertex(Graph* g, int vertex_index) {
    int i;

    for(i = 0; i < g->size; ++i) {
        g->adjacencyMatrix[vertex_index][i] = 0;
        g->adjacencyMatrix[i][vertex_index] = 0;
    }
}

void PrintGraph(Graph g) {
    int i, j;

    for(i = 0; i < g.size; ++i) {
        printf("\n");
        for(j = 0; j < g.size; ++j) {
            printf("%d | ", g.adjacencyMatrix[i][j]);
        }
    }
    printf("\n");
}