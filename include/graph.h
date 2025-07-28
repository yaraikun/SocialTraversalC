/**
 * @file graph.h
 * @brief Core data structures for graph representation.
 *
 * This file defines the fundamental structures and constants used to represent
 * an undirected graph throughout the program. It specifies an adjacency matrix
 * as the primary representation for efficient edge lookups and an adjacency
 * list for storing initial neighbor data.
 */

#ifndef GRAPH_H
#define GRAPH_H

/*
 * MAX_CHARS - Defines the maximum number of characters for a vertex name.
 * The project specification limits vertex IDs to 8 characters plus a null
 * terminator.
 */
#define MAX_CHARS 8

/*
 * MAX_VERTICES - Defines the maximum number of vertices in the graph.
 * The project specification limits the graph to 20 vertices.
 */
#define MAX_VERTICES 20

/**
 * typedef String - A fixed-size character array for vertex names.
 * This provides a convenient alias for vertex labels, ensuring consistent
 * sizing and making function signatures more readable.
 */
typedef char String[MAX_CHARS + 1];

/**
 * struct GraphTag - Represents an undirected graph.
 * @NumVertices:   The total number of vertices currently in the graph.
 * @Vertices:      An array of strings holding the names of each vertex. The
 *                 order is preserved from the input file for matrix labeling.
 * @AdjMatrix:     A matrix where AdjMatrix[i][j] = 1 if an edge exists
 *                 between Vertices[i] and Vertices[j], and 0 otherwise.
 * @Neighbors:     Stores the neighbors for each vertex as read from the input
 *                 file. This is used to build the adjacency list output.
 * @NeighborCount: An array storing the number of neighbors for each vertex,
 *                 corresponding to the Neighbors array.
 */
typedef struct GraphTag {
    int NumVertices;
    String Vertices[MAX_VERTICES];
    int AdjMatrix[MAX_VERTICES][MAX_VERTICES];
    String Neighbors[MAX_VERTICES][MAX_VERTICES];
    int NeighborCount[MAX_VERTICES];
} GraphType;

/**
 * InitGraph() - Initializes a graph to a default empty state.
 * @graph: Pointer to the GraphType structure to be initialized.
 *
 * Sets the number of vertices to zero and clears the adjacency matrix. This
 * function is essential for ensuring a graph is in a clean state before
 * it is populated with data from a file.
 */
void InitGraph(GraphType *graph);

/**
 * GetVertexIndex() - Retrieves the index of a vertex by its name.
 * @graph:      The graph to search within.
 * @vertexName: The string name of the vertex to find.
 *
 * This utility is critical for converting a vertex name (string) into its
 * corresponding integer index, which is required for all adjacency matrix
 * operations.
 *
 * Return: The integer index of the vertex, or -1 if not found.
 */
int GetVertexIndex(GraphType graph, String vertexName);

#endif /* GRAPH_H */
