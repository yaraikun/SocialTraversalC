#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "traversals.h"

int ReadInputFile(const char *filePath, GraphType *graph)
{
    FILE *fp = fopen(filePath, "r");

    if (fp == NULL) {
        return -1;
    }

    String temp_neighbor;
    int i, j;
    int count;
    int neighbor_idx;

    // Read vertex count
    if (fscanf(fp, "%d", &(graph->NumVertices)) != 1) {
        fclose(fp);
        return -1;
    }

    // Read all vertices and their ordered neighbors
    for (i = 0; i < graph->NumVertices; i++) {
        // Read the primary vertex for the current line
        fscanf(fp, "%8s", graph->Vertices[i]);
        graph->NeighborCount[i] = 0;

        // Read all its neighbors until the sentinel '-1'
        while (fscanf(fp, "%8s", temp_neighbor) == 1 && strcmp(temp_neighbor, "-1") != 0) {
            count = graph->NeighborCount[i];

            if (count < MAX_VERTICES) {
                strcpy(graph->Neighbors[i][count], temp_neighbor);
                graph->NeighborCount[i]++;
            }
        }
    }

    fclose(fp);

    // Build the Adjacency Matrix from the read data
    for (i = 0; i < graph->NumVertices; i++) {
        for (j = 0; j < graph->NeighborCount[i]; j++) {
            neighbor_idx = GetVertexIndex(*graph, graph->Neighbors[i][j]);

            if (neighbor_idx != -1)
                graph->AdjMatrix[i][neighbor_idx] = 1;
        }
    }

    return graph->NumVertices;
}

void WriteList(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;
    
    int i, j;

    for (i = 0; i < graph.NumVertices; i++) {
        fprintf(fp, "%s->", graph.Vertices[i]);
        
        for (j = 0; j < graph.NeighborCount[i]; j++) {
            fprintf(fp, "%s->", graph.Neighbors[i][j]);
        }
        
        fprintf(fp, "\\\n");
    }

    fclose(fp);
}

void WriteMatrix(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    int i, j;

    fprintf(fp, "%-9s", "");
    for (i = 0; i < graph.NumVertices; i++)
        fprintf(fp, "%-9s", graph.Vertices[i]);
    fprintf(fp, "\n");

    for (i = 0; i < graph.NumVertices; i++) {
        fprintf(fp, "%-9s", graph.Vertices[i]);
        for (j = 0; j < graph.NumVertices; j++)
            fprintf(fp, "%-9d", graph.AdjMatrix[i][j]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void WriteDFS(const char *filename, GraphType graph, int startVertexIndex)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    String result[MAX_VERTICES];
    int i;

    DFS(graph, startVertexIndex, result);

    for (i = 0; i < graph.NumVertices; i++)
        fprintf(fp, "%s%s", result[i], (i == graph.NumVertices - 1) ? "" : " ");

    fclose(fp);
}
