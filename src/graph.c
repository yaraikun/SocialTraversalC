#include <stdio.h>
#include <string.h>
#include "graph.h"

/**
 * InitGraph() - Initializes the graph structure.
 *
 * @graph: Pointer to the GraphType structure to initialize.
 *
 * Sets the number of vertices to zero. Sets each vertex and neighbor ID to an 
 * empty string. Sets the neighbor counts and the adjacency matrix to zero.
 */
void InitGraph(GraphType *graph)
{
    int i, j;

    graph->NumVertices = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        strcpy(graph->Vertices[i], "");
        graph->NeighborCount[i] = 0;
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->AdjMatrix[i][j] = 0;
            strcpy(graph->Neighbors[i][j], "");
        }
    }
}

/**
 * GetVertexIndex() - Retrieves the index of a vertex by ID.
 *
 * @graph:      The graph to search.
 * @vertexName: The ID of the vertex to find.
 *
 * Performs a linear search over the vertex list to find a match
 * with the given ID and return its index.
 *
 * Return: The index of the vertex if found, -1 otherwise.
 */
int GetVertexIndex(GraphType graph, String vertexName)
{
    int i;

    for (i = 0; i < graph.NumVertices; i++)
        if (strcmp(graph.Vertices[i], vertexName) == 0)
            return i;

    return -1;
}
