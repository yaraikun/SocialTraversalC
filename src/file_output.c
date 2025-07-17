#include <stdio.h>
#include <string.h>
#include "graph.h"

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
