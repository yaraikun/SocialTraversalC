#ifndef FILE_IO_H
#define FILE_IO_H

#include "graph.h"

int ReadInputFile(const char *filePath, GraphType *graph);

void WriteSet(const char *filename, GraphType graph);
void WriteDegree(const char *filename, GraphType graph);
void WriteList(const char *filename, GraphType graph);
void WriteMatrix(const char *filename, GraphType graph);
void WriteBFS(const char *filename, GraphType graph, int startVertexIndex);
void WriteDFS(const char *filename, GraphType graph, int startVertexIndex);

#endif // FILE_IO_H
