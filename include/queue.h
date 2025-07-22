#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"

typedef struct QueueTag {
    int items[MAX_VERTICES];
    int front;
    int rear;
    int count;
} QueueType;

void CreateQueue(QueueType *q);
int IsEmpty(QueueType *q);
int IsFull(QueueType *q);
void Enqueue(QueueType *q, int item);
int Dequeue(QueueType *q);

#endif // QUEUE_H
