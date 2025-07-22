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
void Enqueue(QueueType *q, int item);
void Dequeue(QueueType *q);

#endif // QUEUE_H
