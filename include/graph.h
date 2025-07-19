#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CHARS 8
#define MAX_VERTICES 20

typedef char String[MAX_CHARS + 1];

typedef struct Graph {
    int NumVertices;
    int AdjMatrix[MAX_VERTICES][MAX_VERTICES];
    String Vertices[MAX_VERTICES];
    String Neighbors[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void InitGraph(GraphType *graph);

#endif
