#ifndef SET_H
#define SET_H

#include "graph.h"

typedef struct EdgeTag {
    String v1;
    String v2;
} EdgeType;

int GetSortedVertices(GraphType graph, String result[]);
int GetSortedEdges(GraphType graph, EdgeType result[]);

#endif // SET_H
