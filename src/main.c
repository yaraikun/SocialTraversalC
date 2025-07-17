#include <stdio.h>
#include "graph.h"
#include "sort.h"
#include "file_input.h"
#include "file_output.h"

int main()
{
    GraphType graph;
    char InputFile[256];
    String StartVertex;

    InitGraph(&graph);
    
    printf("Input filename: ");
    if (scanf("%255s", InputFile) != 1) {
        fprintf(stderr, "\nError: Could not read filename.\n");
        return 1;
    }

    printf("Input start vertex for the traversal: ");
    if (scanf("%8s", StartVertex) != 1) {
        fprintf(stderr, "\nError: Could not read start vertex.\n");
        return 1;
    }

    graph.NumVertices = ReadInputFile(InputFile, &graph);

    // Traversal functions

    // File output functions

    return 0;
}
