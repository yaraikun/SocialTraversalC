/**
 * @file    app.c
 * @author  Evan Riley L. Calupig
 * @author  Jon Chester C. Donguines
 * @brief   Main application logic implementation.
 *
 * This file contains the core workflow of the Social Network program. It is
 * responsible for managing user interaction, orchestrating the sequence of
 * function calls (e.g., read file, generate outputs, run traversals), and
 * handling top-level error reporting like "File not found."
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "file_io.h"
#include "graph.h"

/**
 * get_output_filename() - Constructs an output filename with a given suffix.
 *
 * @input_path:  The original input file path.
 * @suffix:      The suffix to append to the output file name (e.g. "-BFS").
 * @output_path: The buffer that will store the resulting filename.
 *
 * Extracts the base filename (excluding directory path and extension)
 * from the input path, appends the given suffix, and adds a ".TXT" extension.
 * This is a static helper function used to generate output filenames for the
 * graph representations.
 */
static void get_output_filename(const char *input_path, const char *suffix,
                                char *output_path)
{
    char temp_path[256];
    char *base_name;

    strcpy(temp_path, input_path);

    base_name = strrchr(temp_path, '/');
    if (base_name == NULL)
        base_name = strrchr(temp_path, '\\');

    if (base_name == NULL) {
        base_name = temp_path;
    } else {
        base_name++;
    }

    char *base_name_copy = strdup(base_name);
    char *token = strtok(base_name_copy, ".");

    sprintf(output_path, "%s%s.TXT", token, suffix);
    free(base_name_copy);
}

/**
 * RunProgram() - Main logic for user input, data processing, and output.
 *
 * Prompts the user for an input file name and reads a graph from the file if
 * found. The function then writes set, degree, matrix, and list representations
 * of the graph to separate output files. The output filenames are generated
 * using get_output_filename() to append appropriate suffixes to the input
 * filename. If the file was not found, the program terminates.
 *
 * Also prompts for a starting vertex ID to write the BFS and DFS traversal
 * files. If the vertex is not found in the graph, traversal outputs are
 * skipped.
 */
void RunProgram(void)
{
    GraphType graph;
    char inputFilename[256];
    char outputFilename[265];
    String startVertex;
    int startVertexIndex;

    InitGraph(&graph);

    printf("Input filename: ");
    if (scanf("%255s", inputFilename) != 1) {
        fprintf(stderr, "Error reading filename input.\n");
        return;
    }

    // Input Output 1 - 4
    if (ReadInputFile(inputFilename, &graph) == -1) {
        printf("File %s not found.\n", inputFilename);
        return;
    }

    // Output 1 - 4
    get_output_filename(inputFilename, "-SET", outputFilename);
    WriteSet(outputFilename, graph);

    get_output_filename(inputFilename, "-DEGREE", outputFilename);
    WriteDegree(outputFilename, graph);

    get_output_filename(inputFilename, "-LIST", outputFilename);
    WriteList(outputFilename, graph);

    get_output_filename(inputFilename, "-MATRIX", outputFilename);
    WriteMatrix(outputFilename, graph);

    // Input for Output 5 - 6
    printf("Input start vertex for the traversal: ");
    scanf("%8s", startVertex);

    startVertexIndex = GetVertexIndex(graph, startVertex);

    if (startVertexIndex == -1) {
        printf("Vertex %s not found.\n", startVertex);
        return;
    }

    // Output 5 - 6
    get_output_filename(inputFilename, "-BFS", outputFilename);
    WriteBFS(outputFilename, graph, startVertexIndex);

    get_output_filename(inputFilename, "-DFS", outputFilename);
    WriteDFS(outputFilename, graph, startVertexIndex);
}
