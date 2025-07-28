/**
 * @file    traversals.h
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   Declarations for graph traversal algorithms (BFS and DFS).
 *
 * This file defines the public interface for the Breadth-First Search (BFS)
 * and Depth-First Search (DFS) algorithms. The functions declared here are
 * responsible for producing an ordered list of visited vertices based on a
 * given starting point, adhering to the project's tie-breaking rules.
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
