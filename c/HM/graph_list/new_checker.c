#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
	Graph g;

	InitGraph(&g);

	// Add vertex 10
	AddVertex(&g, 10);
	RemoveVertex(&g, 10);
	// Print the Graph
	printf("Empty Graph:\n");
	PrintGraph(g);
	printf("============\n");

	/* Add vertices to the Graph */
	AddVertex(&g, 1);
	AddVertex(&g, 2);
	AddVertex(&g, 3);
	AddVertex(&g, 5);
	// Check and Add Edge
	if (HasVertex(g, 3) && HasVertex(g, 5))
	{
		AddEdge(g, 3, 5, 11);
	}
	AddVertex(&g, 4);

	// Print the Graph
	printf("Graph:\n");
	PrintGraph(g);

	// Add edges to the Graph
	// when adding some fictive - shouldnt crash
	AddEdge(g, 1, 2, 7);
	AddEdge(g, 3, 1, 8);
	AddEdge(g, 3, 4, 12);
	if (!HasEdge(g, 4, 3))
	{
		AddEdge(g, 4, 3, 15);
	}
	AddEdge(g, 2, 3, 9);
	AddEdge(g, 3, 2, 13);
	// Done up
	//AddEdge(g, 3, 5, 11);
	AddEdge(g, 2, 5, 10);
	printf("Graph edges added.\n");
	PrintGraph(g);

	printf("Now trying some bad edges\n");
	// Add edges to non existing vertices (dont crash)
	//printf("Added 10\n");
	PrintGraph(g);
	AddEdge(g, 6, 5, 2);
	//printf("no Add 6\n");
	AddEdge(g, 4, 7, 2);
	//printf("no Add to 7\n");
	AddEdge(g, 6, 10, 3);
	//printf("no Add 6\n");
	AddEdge(g, 8, 6, 1);
	//printf("no Add 8 to 6\n");

	// Print the Graph
	printf("Change weight 3->5 to 17 and print Graph again\n");
	UpdateEdge(g, 3, 5, 17);
	// update a non existing edge
	UpdateEdge(g, 4, 7, 99);
	//printf("no Update 3 to 12\n");
	UpdateEdge(g, 7, 5, 20);
	//printf("no Update 7 to 5\n");
	PrintGraph(g);

	// Remove vertices 
	printf("remove vertice and print Graph again\n");
	RemoveVertex(&g, 2);
	PrintGraph(g);
	// remove a non existing vertice
	printf("removing a non existing vertice\n");
	RemoveVertex(&g, 6);

	printf("Print Graph last time\n");
	// Print the Graph after removing vertice 2
	PrintGraph(g);

}