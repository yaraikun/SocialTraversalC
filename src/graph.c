#include <stdio.h>
#include <string.h>
#include "graph.h"

void InitGraph(GraphType *graph)
{
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->AdjMatrix[i][j] = 0;
            strcpy(graph->Neighbors[i][j], "");
        }

        strcpy(graph->Vertices[i], "");
    }
}
