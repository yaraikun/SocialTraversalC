#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CHARS 8
#define MAX_VERTICES 20

typedef char String[MAX_CHARS + 1];

typedef struct GraphTag {
    int NumVertices;
    String Vertices[MAX_VERTICES];
    int AdjMatrix[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void InitGraph(GraphType *graph);
int GetVertexIndex(GraphType graph, String vertexName);

#endif
