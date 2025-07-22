#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "graph.h"
#include "traversals.h"
#include "sort.h"
#include "set.h"

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

void WriteSet(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    int i;

    String sortedVertices[MAX_VERTICES];
    int vertex_count = GetSortedVertices(graph, sortedVertices);

    EdgeType sortedEdges[MAX_VERTICES * MAX_VERTICES];
    int edge_count = GetSortedEdges(graph, sortedEdges);

    fprintf(fp, "V(G)={");
    for (i = 0; i < vertex_count; i++)
        fprintf(fp, "%s%s", sortedVertices[i], (i == vertex_count - 1) ? "" : ",");
    fprintf(fp, "}\n");

    fprintf(fp, "E(G)={");
    for (i = 0; i < edge_count; i++) {
        fprintf(fp, "(%s,%s)", sortedEdges[i].v1, sortedEdges[i].v2);

        if (i < edge_count - 1)
            fprintf(fp, ",");
    }

    fprintf(fp, "}");

    fclose(fp);
}

void WriteDegree(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    String sortedVertices[MAX_VERTICES];
    int i, j;
    int original_index;
    int degree;

    for(i = 0; i < graph.NumVertices; i++)
        strcpy(sortedVertices[i], graph.Vertices[i]);

    SortStrArr(sortedVertices, graph.NumVertices);

    for (i = 0; i < graph.NumVertices; i++) {
        original_index = GetVertexIndex(graph, sortedVertices[i]);
        degree = 0;

        for(j = 0; j < graph.NumVertices; j++)
            degree += graph.AdjMatrix[original_index][j];

        fprintf(fp, "%s %d\n", sortedVertices[i], degree);
    }

    fclose(fp);
}

void WriteList(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;
    
    int i, j;

    for (i = 0; i < graph.NumVertices; i++) {
        fprintf(fp, "%s->", graph.Vertices[i]);
        
        for (j = 0; j < graph.NeighborCount[i]; j++)
            fprintf(fp, "%s->", graph.Neighbors[i][j]);
        
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

void WriteBFS(const char *filename, GraphType graph, int startVertexIndex)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    String result[MAX_VERTICES];
    int i;

    BFS(graph, startVertexIndex, result);

    for (i = 0; i < graph.NumVertices; i++)
        fprintf(fp, "%s%s", result[i], (i == graph.NumVertices - 1) ? "" : " ");

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
