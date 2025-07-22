#include <string.h>
#include "set.h"
#include "sort.h"

static void SwapEdges(EdgeType *edge1, EdgeType *edge2)
{
    EdgeType temp = *edge1;
    *edge1 = *edge2;
    *edge2 = temp;
}

static int PartitionEdges(EdgeType edgeArr[], int low, int high)
{
    EdgeType pivot = edgeArr[high];
    int i = low - 1;
    int j;
    int cmp;

    for (j = low; j < high; j++) {
        cmp = strcmp(edgeArr[j].v1, pivot.v1);

        if (cmp == 0)
            cmp = strcmp(edgeArr[j].v2, pivot.v2);

        if (cmp < 0) {
            i++;
            SwapEdges(&edgeArr[i], &edgeArr[j]);
        }
    }

    SwapEdges(&edgeArr[i + 1], &edgeArr[high]);

    return i + 1;
}

static void QuickSortEdges(EdgeType edgeArr[], int low, int high)
{
    if (low < high) {
        int pi = PartitionEdges(edgeArr, low, high);
        QuickSortEdges(edgeArr, low, pi - 1);
        QuickSortEdges(edgeArr, pi + 1, high);
    }
}

int GetSortedVertices(GraphType graph, String result[])
{
    int i;

    for (i = 0; i < graph.NumVertices; i++)
        strcpy(result[i], graph.Vertices[i]);

    SortStrArr(result, graph.NumVertices);

    return graph.NumVertices;
}

int GetSortedEdges(GraphType graph, EdgeType result[])
{
    int i, j;
    int edge_count = 0;

    for (i = 0; i < graph.NumVertices; i++) {
        for (j = i + 1; j < graph.NumVertices; j++) {
            if (graph.AdjMatrix[i][j] == 1 || graph.AdjMatrix[j][i] == 1) {
                if (strcmp(graph.Vertices[i], graph.Vertices[j]) < 0) {
                    strcpy(result[edge_count].v1, graph.Vertices[i]);
                    strcpy(result[edge_count].v2, graph.Vertices[j]);
                } else {
                    strcpy(result[edge_count].v1, graph.Vertices[j]);
                    strcpy(result[edge_count].v2, graph.Vertices[i]);
                }

                edge_count++;
            }
        }
    }

    if (edge_count > 1)
        QuickSortEdges(result, 0, edge_count - 1);

    return edge_count;
}
