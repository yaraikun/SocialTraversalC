/**
 * @file traversals.h
 * @brief Declarations for graph traversal algorithms.
 *
 * This file declares the Breadth-First Search (BFS) and Depth-First Search
 * (DFS) algorithms. These functions are responsible for visiting graph
 * vertices in a specific order, starting from a given vertex. The results
 * are used to generate the BFS and DFS output files.
 */

#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include "graph.h"

/**
 * BFS() - Performs a Breadth-First Search on the graph.
 * @graph:            The graph data structure to traverse.
 * @startVertexIndex: The index of the vertex where the traversal begins.
 * @result:           An output array to store the names of vertices in the
 *                    order they are visited.
 *
 * This function implements the BFS algorithm. When multiple neighbors are
 * candidates to be visited, it chooses the one with the lexicographically
 * smallest name first, as required by the project specifications.
 */
void BFS(GraphType graph, int startVertexIndex, String result[]);

/**
 * DFS() - Performs a Depth-First Search on the graph.
 * @graph:            The graph data structure to traverse.
 * @startVertexIndex: The index of the vertex where the traversal begins.
 * @result:           An output array to store the names of vertices in the
 *                    order they are visited.
 *
 * This function implements the DFS algorithm recursively. When multiple
 * neighbors are candidates to be visited from a vertex, it explores the
 * one with the lexicographically smallest name first.
 */
void DFS(GraphType graph, int startVertexIndex, String result[]);

#endif /* TRAVERSALS_H */
