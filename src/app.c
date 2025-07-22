#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "graph.h"
#include "file_io.h"

static void get_output_filename(const char* input_name, const char* suffix, char* output_name) {
    int input_len = strlen(input_name);

    char base_name[256];
    int base_name_len = 0;

    int i;
    int found = 0;

    i = input_len - 1;
    while (i >= 0 && found != 1) {
        if (input_name[i] == '.')
            found = 1;
        base_name[i] = input_name[i];
        base_name_len++;

        i++;
    }

    base_name[base_name_len] = '\0';

    strcpy(output_name, base_name);
    strcat(output_name, suffix);
    strcat(output_name, ".TXT");

}

void RunProgram(void)
{
    GraphType graph;
    char inputFilename[256];
    char outputFilename[265];
    String startVertex;
    int startVertexIndex;

    InitGraph(&graph);
    
    printf("Input filename: ");
    if(scanf("%255s", inputFilename) != 1) {
        fprintf(stderr, "Error reading filename input.\n");
        return;
    }

    // Input Output 1 - 4
    if (ReadInputFile(inputFilename, &graph) == -1) {
        printf("File %s not found.\n", inputFilename);
        return;
    }

    // Output 1 - 4
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
    get_output_filename(inputFilename, "-DFS", outputFilename);
    WriteDFS(outputFilename, graph, startVertexIndex);
}
