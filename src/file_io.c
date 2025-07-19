#include <stdio.h>
#include <string.h>
#include "graph.h"

int ReadInputFile(const char *FilePath, GraphType *graph)
{
    FILE *InputFile = fopen(FilePath, "r");
    int i, j, k;
    int NumVertices;
    String vertex;

    if (InputFile == NULL) {
        fprintf(stderr, "File %s not found.\n", FilePath);
        return -1;
    }

    NumVertices = 0;

    if (fscanf(InputFile, "%d", &NumVertices) != 1) {
        fprintf(stderr, "Error: Failed to read number of points from %s\n", FilePath);
        fclose(InputFile);
        return -1;
    }

    if (NumVertices > MAX_VERTICES || NumVertices < 0) {
        fprintf(stderr, "Error: Number of points (%d) is out of valid range (0-%d).\n", NumVertices, MAX_VERTICES);
        fclose(InputFile);
        return -1;
    }

    for (i = 0; i < NumVertices; i++) {
        j = 0;
        
        // Scan vertex
        fscanf(InputFile, "%8s", vertex);

        // Add to vertex array
        strcpy(graph->Vertices[i], vertex);

        do {
            // Scan neighbor
            fscanf(InputFile, "%8s", vertex);

            // Check if -1
            if(strcmp(vertex, "-1") == 0)
                break;

            // If not, store to temp string array
            strcpy(graph->Neighbors[i][j], vertex);

            j++;

        // Repeat until -1
        } while (1);
    }

    // Add 1 to AdjMatrix array column if key found in the corresponding row
    for (i = 0; i < NumVertices; i++)
        for (j = 0; j < NumVertices; j++)
            for (k = 0; k < NumVertices; k++)
                if(strcmp(graph->Vertices[j], graph->Neighbors[i][k]) == 0)
                    graph->AdjMatrix[i][j] = 1;

    return NumVertices;
}

/***********************************
 * 
 * TO BE CONVERTED TO FILE OUTPUT
 * 
 ***********************************/

void PrintSet(GraphType graph)
{
    
}

void PrintDegree(GraphType graph)
{

}

void PrintList(GraphType graph)
{
    int i, j;
    
    for (i = 0; i < graph.NumVertices; i++) {
        printf("%s->", graph.Vertices[i]);

        for (j = 0; j < graph.NumVertices; j++)
            if(strcmp(graph.Neighbors[i][j], "") != 0)    
                printf("%s->", graph.Neighbors[i][j]);
        
        printf("\\\n");
    }
}

void PrintMatrix(GraphType graph)
{
    int i, j;

    printf("%9s", "");

    for (i = 0; i < graph.NumVertices; i++)
        printf("%-9s", graph.Vertices[i]);
    
    printf("\n");

    for (i = 0; i < graph.NumVertices; i++) {
        printf("%-9s", graph.Vertices[i]);
        
        for (j = 0; j < graph.NumVertices; j++)
            printf("%-9d", graph.AdjMatrix[i][j]);
        
        printf("\n");
    }
}
