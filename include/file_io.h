/**
 * @file file_io.h
 * @brief Declarations for file input and output operations.
 *
 * This file provides the interfaces for reading graph data from a text file
 * and for writing the various required output files. Each "Write" function
 * is tailored to a specific output format as defined by the project specs,
 * such as the vertex set, adjacency list, or traversal results.
 */

#ifndef FILE_IO_H
#define FILE_IO_H

#include "graph.h"

/**
 * ReadInputFile() - Parses a graph data file.
 * @filePath: Path to the input text file.
 * @graph:    Pointer to the GraphType structure to populate.
 *
 * Reads an adjacency list from the given file and populates the graph
 * data structure, including the adjacency matrix and vertex list. It returns
 * a status code indicating success or failure (e.g., file not found).
 *
 * Return: 0 on success, -1 on failure (e.g., file not found).
 */
int ReadInputFile(const char *filePath, GraphType *graph);

/**
 * WriteSet() - Writes the vertex and edge sets to a file.
 * @filename: The name of the output file (e.g., "G-SET.TXT").
 * @graph:    The graph data structure containing vertices and edges.
 *
 * Generates Output File #1, which contains two lines:
 * 1. A sorted list of all vertex names.
 * 2. A sorted list of all edges.
 */
void WriteSet(const char *filename, GraphType graph);

/**
 * WriteDegree() - Writes the degree of each vertex to a file.
 * @filename: The name of the output file (e.g., "G-DEGREE.TXT").
 * @graph:    The graph data structure.
 *
 * Generates Output File #2, listing each vertex in alphabetical order
 * followed by its calculated degree.
 */
void WriteDegree(const char *filename, GraphType graph);

/**
 * WriteList() - Writes the adjacency list representation to a file.
 * @filename: The name of the output file (e.g., "G-LIST.TXT").
 * @graph:    The graph data structure.
 *
 * Generates Output File #3, which represents the graph as an adjacency
 * list. The order of vertices in the list matches the order from the
 * original input file.
 */
void WriteList(const char *filename, GraphType graph);

/**
 * WriteMatrix() - Writes the adjacency matrix representation to a file.
 * @filename: The name of the output file (e.g., "G-MATRIX.TXT").
 * @graph:    The graph data structure.
 *
 * Generates Output File #4, displaying the graph's adjacency matrix.
 * Both row and column headers are the vertex names, ordered as they
 * appeared in the input file.
 */
void WriteMatrix(const char *filename, GraphType graph);

/**
 * WriteBFS() - Writes the Breadth-First Search traversal result to a file.
 * @filename:         The name of the output file (e.g., "G-BFS.TXT").
 * @graph:            The graph data structure.
 * @startVertexIndex: The index of the starting vertex for the traversal.
 *
 * Generates Output File #5 by performing a BFS traversal and writing the
 * sequence of visited vertices to the specified file.
 */
void WriteBFS(const char *filename, GraphType graph, int startVertexIndex);

/**
 * WriteDFS() - Writes the Depth-First Search traversal result to a file.
 * @filename:         The name of the output file (e.g., "G-DFS.TXT").
 * @graph:            The graph data structure.
 * @startVertexIndex: The index of the starting vertex for the traversal.
 *
 * Generates Output File #6 by performing a DFS traversal and writing the
 * sequence of visited vertices to the specified file.
 */
void WriteDFS(const char *filename, GraphType graph, int startVertexIndex);

#endif /* FILE_IO_H */
