/**
 * @file set.h
 * @brief Functions for extracting and organizing vertex and edge sets.
 *
 * This module is designed specifically to prepare the data required for
 * "Output File #1". It provides functions to gather all unique vertices and
 * edges from the graph data structure and sort them according to the
 * project's specifications.
 */

#ifndef SET_H
#define SET_H

#include "graph.h"

/**
 * struct EdgeTag - Represents a single graph edge.
 * @v1: The first vertex in the edge pair.
 * @v2: The second vertex in the edge pair.
 *
 * This structure is used to hold an edge. To maintain consistency, the
 * vertices within an edge are stored in alphabetical order (v1 < v2).
 */
typedef struct EdgeTag {
    String v1;
    String v2;
} EdgeType;

/**
 * GetSortedVertices() - Extracts and sorts all vertices from the graph.
 * @graph:  The graph data structure to process.
 * @result: An output array of strings to store the sorted vertex names.
 *
 * Return: The total number of vertices found.
 */
int GetSortedVertices(GraphType graph, String result[]);

/**
 * GetSortedEdges() - Extracts and sorts all unique edges from the graph.
 * @graph:  The graph data structure to process.
 * @result: An output array of EdgeType to store the sorted edges.
 *
 * Iterates through the adjacency matrix to find all unique edges. Each edge
 * is normalized (v1 < v2) and the final list is sorted alphabetically.
 *
 * Return: The total number of unique edges found.
 */
int GetSortedEdges(GraphType graph, EdgeType result[]);

#endif /* SET_H */
