#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversals.h"
#include "graph.h"
#include "queue.h"
#include "sort.h"

void DFSRecursive(GraphType graph, int u_idx, int visited[], String result[], int *count)
{
    int i;
    String neighbors[MAX_VERTICES];
    int neighbor_count = 0;
    int v_idx;

    visited[u_idx] = 1;
    strcpy(result[(*count)++], graph.Vertices[u_idx]);

    for (i = 0; i < graph.NumVertices; i++)
        if (graph.AdjMatrix[u_idx][i] == 1)
            strcpy(neighbors[neighbor_count++], graph.Vertices[i]);

    SortStrArr(neighbors, neighbor_count);

    for (i = 0; i < neighbor_count; i++) {
        v_idx = GetVertexIndex(graph, neighbors[i]);
        if (v_idx != -1 && !visited[v_idx])
            DFSRecursive(graph, v_idx, visited, result, count);
    }
}

void DFS(GraphType graph, int startVertexIndex, String result[])
{
    int visited[MAX_VERTICES] = {0};
    int count = 0;

    DFSRecursive(graph, startVertexIndex, visited, result, &count);
}

void BFS(GraphType graph, int startVertexIndex, String result[])
{
    int visited[MAX_VERTICES] = {0};

    QueueType q;
    int count = 0;
    int i;

    int u_idx;
    int v_idx;

    int neighbor_count;
    String neighbors[MAX_VERTICES];

    CreateQueue(&q);

    visited[startVertexIndex] = 1;
    Enqueue(&q, startVertexIndex);

    while (!IsEmpty(&q)) {
        u_idx = Dequeue(&q);
        strcpy(result[count++], graph.Vertices[u_idx]);

        neighbor_count = 0;
        for (i = 0; i < graph.NumVertices; i++)
            if (graph.AdjMatrix[u_idx][i] == 1)
                strcpy(neighbors[neighbor_count++], graph.Vertices[i]);

        SortStrArr(neighbors, neighbor_count);

        for (i = 0; i < neighbor_count; i++) {
            v_idx = GetVertexIndex(graph, neighbors[i]);
            if (v_idx != -1 && !visited[v_idx]) {
                visited[v_idx] = 1;
                Enqueue(&q, v_idx);
            }
        }
    }
}
