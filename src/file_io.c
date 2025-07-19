#include <stdio.h>
#include <string.h>
#include "graph.h"

int ReadInputFile(const char *filePath, GraphType *graph)
{
    FILE *fp = fopen(filePath, "r");
    String temp;
    int i, j;

    if (fp == NULL) {
        fprintf(stderr, "File %s not found.\n", filePath);
        return -1;
    }

    // PASS 1: Read number of vertices and their names
    if (fscanf(fp, "%d", &(graph->NumVertices)) != 1) {
        fprintf(stderr, "Error: Could not read vertex count from %s\n",
                filePath);
        fclose(fp);
        return -1;
    }

    for (i = 0; i < graph->NumVertices; i++) {
        fscanf(fp, "%8s", graph->Vertices[i]);

        do {
            fscanf(fp, "%8s", temp);
        } while (strcmp(temp, "-1") != 0);
    }

    // PASS 2: Rewind and build the Adjacency Matrix
    rewind(fp);
    fscanf(fp, "%d", &i);

    for (i = 0; i < graph->NumVertices; i++) {
        fscanf(fp, "%8s", temp);

        while (fscanf(fp, "%8s", temp) == 1 && strcmp(temp, "-1") != 0) {
            j = GetVertexIndex(*graph, temp);

            if (j != -1)
                graph->AdjMatrix[i][j] = 1;
        }
    }

    fclose(fp);
    return graph->NumVertices;
}
