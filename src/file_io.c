#include "file_io.h"
#include "graph.h"
#include "set.h"
#include "sort.h"
#include "traversals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ReadInputFile() - Reads graph data from a file and populates the graph
 * structure.
 *
 * @filePath: Path to the input file.
 * @graph:    Pointer to the GraphType structure to populate.
 *
 * This function reads the number of vertices, their IDs, and their neighbors
 * from a file. For each vertex, it reads its neighbors until the sentinel
 * value "-1" is found. The adjacency matrix is then constructed based on
 * the neighbor relationships.
 *
 * Return: Number of vertices read if successful, -1 otherwise.
 */
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
        while (fscanf(fp, "%8s", temp_neighbor) == 1 &&
               strcmp(temp_neighbor, "-1") != 0) {
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

/**
 * WriteSet() - Writes the vertex and edge set representation of a graph to a
 * file.
 *
 * @filename: The name of the output file.
 * @graph:    The graph to be written.
 *
 * Produces an output file where vertices and edges are listed using
 * set representation, e.g., V(G) = {A,B,C} and E(G) = {(A,B),(B,C)}.
 * Vertices and edges are sorted in ascending order. The filename's
 * prefix is used as the label (e.g., "G" in V(G)).
 */
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

    char *base_name = strdup(filename);
    char *token = strtok(base_name, "-");

    fprintf(fp, "V(%s)={", token);
    for (i = 0; i < vertex_count; i++)
        fprintf(fp, "%s%s", sortedVertices[i],
                (i == vertex_count - 1) ? "" : ",");
    fprintf(fp, "}\n");

    fprintf(fp, "E(%s)={", token);
    for (i = 0; i < edge_count; i++) {
        fprintf(fp, "(%s,%s)", sortedEdges[i].v1, sortedEdges[i].v2);

        if (i < edge_count - 1)
            fprintf(fp, ",");
    }

    free(base_name);
    fprintf(fp, "}");
    fclose(fp);
}

/**
 * WriteDegree() - Writes the degree of each vertex of a graph to a file.
 *
 * @filename: The name of the output file.
 * @graph:    The graph to be written.
 *
 * Calculates and writes the degree of each vertex (the number of
 * edges connected) in lexicographical order of vertex IDs. Each line of
 * the file contains a vertex ID followed by its degree.
 */
void WriteDegree(const char *filename, GraphType graph)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
        return;

    String sortedVertices[MAX_VERTICES];
    int i, j;
    int original_index;
    int degree;

    for (i = 0; i < graph.NumVertices; i++)
        strcpy(sortedVertices[i], graph.Vertices[i]);

    SortStrArr(sortedVertices, graph.NumVertices);

    for (i = 0; i < graph.NumVertices; i++) {
        original_index = GetVertexIndex(graph, sortedVertices[i]);
        degree = 0;

        for (j = 0; j < graph.NumVertices; j++)
            degree += graph.AdjMatrix[original_index][j];

        fprintf(fp, "%s %d\n", sortedVertices[i], degree);
    }

    fclose(fp);
}

/**
 * WriteList() - Writes the adjacency list representation of a graph to a file.
 *
 * @filename: The name of the output file.
 * @graph:    The graph to be written.
 *
 * For each vertex, prints the vertex followed by its neighbors, each separated
 * by an arrow (e.g., A->B->C->\). The backslash denotes the NULL pointer.
 */
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

/**
 * WriteMatrix() - Writes the adjacency matrix representation of a graph to a
 * file.
 *
 * @filename: The name of the output file.
 * @graph:    The graph to be written.
 *
 * Outputs a tabular matrix with vertex IDs as both row and column headers,
 * and matrix entries 0 or 1 indicating whether an edge exists from row vertex
 * to column vertex.
 */
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

/**
 * WriteBFS() - Writes the result of a Breadth-First Search (BFS) traversal to a
 * file.
 *
 * @filename:         The name of the output file.
 * @graph:            The graph to be written.
 * @startVertexIndex: The index of the vertex to start the BFS from.
 *
 * Performs BFS on the graph and writes the visited vertices separated by a
 * space in BFS order to a file.
 */
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

/**
 * WriteDFS() - Writes the result of a Depth-First Search (DFS) traversal to a
 * file.
 *
 * @filename:         The name of the output file.
 * @graph:            The graph to be written.
 * @startVertexIndex: The index of the vertex to start the DFS from.
 *
 * Performs DFS on the graph and writes the visited vertices separated by a
 * space in DFS order to a file.
 */
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
