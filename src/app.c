#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "graph.h"
#include "file_io.h"

static void get_output_filename(const char* input_path, const char* suffix, char* output_path) {
    char temp_path[256];
    char* base_name;
    
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
