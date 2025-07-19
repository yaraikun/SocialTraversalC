#include <stdio.h>
#include <string.h>
#include "graph.h"

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

int GetVertexIndex(GraphType graph, String vertexName)
{
    int i;

    for (i = 0; i < graph.NumVertices; i++)
        if (strcmp(graph.Vertices[i], vertexName) == 0)
            return i;

    return -1;
}
