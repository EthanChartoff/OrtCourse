#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))


// can only make one graph, because you cant save the length
// of the graph with thie implementation.
int mat_length;

int** initGraph(int n) {
    int **graph = (int **)malloc(n * sizeof(int *)), i;
    if(graph == NULL) {
        printf("failed to alloc data to *mat");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; ++i) {
        graph[i] = (int *)calloc(n, sizeof(int));
        if(graph[i] == NULL) {
            printf("failed to alloc data to *mat");
            exit(EXIT_FAILURE);
        }
    } 
    mat_length = n;

    return graph;
}

int hasVertix(int **mat, int v) {
    return v < mat_length && mat[v][v] != 0;
}

int hasEdge(int **mat, int x, int y) {
    return !!mat[x][y];
}

void addEdge(int ***mat, int x, int y, int cost) {
    if(hasVertix(*mat, x) && hasVertix(*mat, y))
        (*mat)[x][y] = cost;
}

void removeEdge(int ***mat, int x, int y) {
    (*mat)[x][y] = 0;
}

void addVertix(int ***mat, int n) {
    int i, j, prev_len, **tmp_mat;

    if(hasVertix(*mat, n))
        return;
    else if(n < mat_length) {
        (*mat)[n][n] = 1;
        return;
    }
    
    prev_len = mat_length;
    mat_length = n + 1;

    tmp_mat = (int **)malloc(mat_length * sizeof(int *));
    if(tmp_mat == NULL) {
        printf("failed to alloc data to *mat");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < mat_length; ++i) {
        tmp_mat[i] = (int *)calloc(mat_length, sizeof(int));
        if(tmp_mat[i] == NULL) {
            printf("failed to alloc data to *mat");
            exit(EXIT_FAILURE);
        }
        for(j = 0; j < mat_length; ++j) {
            if(i < prev_len && j < prev_len) {
                tmp_mat[i][j] = (*mat)[i][j];
            } 
        }
    }

    for(i = 0; i < prev_len; ++i)
        free((*mat)[i]);
    free(*mat);

    *mat = tmp_mat;

    (*mat)[n][n] = 1;
    return;
}

void removeVertix(int ***mat, int n, int v) {
    int i;

    for(i = 0; i < mat_length; ++i) {
        (*mat)[v][i] = 0;
        (*mat)[i][v] = 0;
    }
}

void changeWeight(int ***mat, int x, int y, int cost) {
    (*mat)[x][y] = cost;
}

void print_graph(int **mat) {
    int i, j;

    for(i = 0; i < mat_length; ++i) {
        printf("\n");
        for(j = 0; j < mat_length; ++j) {
            printf("%d", mat[i][j]);
        }
    }
    printf("\n");
}