#include "set.h"
#include "sort.h"
#include <string.h>

/**
 * SwapEdges() - Swaps the contents of two EdgeType structures.
 *
 * @edge1: Pointer to the first edge.
 * @edge2: Pointer to the second edge.
 *
 * This is a static helper function that exchanges the data of two edges
 * using a temporary variable.
 */
static void SwapEdges(EdgeType *edge1, EdgeType *edge2)
{
    EdgeType temp = *edge1;
    *edge1 = *edge2;
    *edge2 = temp;
}

/**
 * PartitionEdges() - The partition scheme for QuickSortEdges().
 *
 * @edgeArr:  The array of edges being sorted.
 * @low:      The starting index of the subarray to partition.
 * @high:     The ending index of the subarray to partition.
 *
 * A static helper function for QuickSortEdges(). It takes the last element as a
 * pivot and rearranges the array such that all edges that come
 * lexicographically before the pivot are placed before it, and all edges that
 * come after are placed after it.
 *
 * Return: The partition index of the pivot element.
 */
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

/**
 * QuickSortEdges() - Sorts edges in ascending order using QuickSort.
 *
 * @edgeArr:  The array of edges being sorted.
 * @low:      The starting index of the subarray to partition.
 * @high:     The ending index of the subarray to partition.
 *
 * This function recursively sorts a subarray of edges using the QuickSort
 * algorithm.
 */
static void QuickSortEdges(EdgeType edgeArr[], int low, int high)
{
    if (low < high) {
        int pi = PartitionEdges(edgeArr, low, high);
        QuickSortEdges(edgeArr, low, pi - 1);
        QuickSortEdges(edgeArr, pi + 1, high);
    }
}

/**
 * GetSortedVertices() - Retrieves all vertices in sorted order.
 *
 * @graph:  The graph whose vertices are to be retrieved.
 * @result: An array to store the sorted vertex IDs.
 *
 * Copies all vertex IDs from the graph into the result array, then sorts them
 * in ascending order.
 *
 * Return: The number of vertices copied and sorted.
 */
int GetSortedVertices(GraphType graph, String result[])
{
    int i;

    for (i = 0; i < graph.NumVertices; i++)
        strcpy(result[i], graph.Vertices[i]);

    SortStrArr(result, graph.NumVertices);

    return graph.NumVertices;
}

/**
 * GetSortedEdges() - Retrieves all unique edges in sorted order.
 *
 * @graph:  The graph whose edges are to be retrieved.
 * @result: An array to store the sorted edges.
 *
 * Iterates over the upper triangle of the adjacency matrix to retrieve
 * all unique edges. Each edge is stored with its endpoints ordered
 * lexicographically. The resulting edge array is then sorted by v1 then v2
 * using QuickSortEdges().
 *
 * Return: The number of edges found and sorted.
 */
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
