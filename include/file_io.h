#ifndef FILE_IO_H
#define FILE_IO_H

#include "graph.h"

int ReadInputFile(const char *FilePath, GraphType *graph);

void PrintSet(GraphType graph);
void PrintDegree(GraphType graph);
void PrintList(GraphType graph);
void PrintMatrix(GraphType graph);

#endif // FILE_IO_H
