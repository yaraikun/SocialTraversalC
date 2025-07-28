#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversals.h"
#include "graph.h"
#include "queue.h"
#include "sort.h"

/**
 * DFSRecursive() - Helper function to perform recursive Depth-First Search (DFS).
 *
 * @graph:      The graph to traverse.
 * @u_idx:      The index of the current vertex being visited.
 * @visited:    An array storing the IDs of visited vertices.
 * @result:     An array to store the traversal result in order.
 * @count:      The number of visited vertices.
 *
 * Recursively explores the graph from vertex u_idx using DFS. Neighboring
 * vertices are visited in lexicographical order based on their IDs. Each vertex 
 * is visited osly once. The result array will store the traversal sequence.
 */
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

/**
 * DFS() - Performs Depth-First Search (DFS) on a graph.
 *
 * @graph:              The graph to traverse.
 * @startVertexIndex:   The index of the starting vertex.
 * @result:             An array to store the traversal result in order.
 *
 * Performs a recursive DFS traversal starting from startVertexIndex.
 * The result array will store the IDs of the vertices visited in DFS order.
 */
void DFS(GraphType graph, int startVertexIndex, String result[])
{
    int visited[MAX_VERTICES] = {0};
    int count = 0;

    DFSRecursive(graph, startVertexIndex, visited, result, &count);
}

/**
 * BFS() - Performs Breadth-First Search (BFS) on a graph.
 *
 * @graph:              The graph to traverse.
 * @startVertexIndex:   The index of the starting vertex.
 * @result:             An array to store the traversal result in order.
 *
 * Performs an iterative BFS traversal starting from startVertexIndex. Vertices 
 * are visited level-by-level, and neighbors are enqueued in lexicographical order.
 * Each vertex is visited only once. The result array will store the traversal sequence.
 */
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
