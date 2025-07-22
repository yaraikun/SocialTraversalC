#include "queue.h"
#include "graph.h"

void CreateQueue(QueueType *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int IsEmpty(QueueType *q)
{
    return q->count == 0;
}

int IsFull(QueueType *q)
{
    return q->count == MAX_VERTICES;
}

void Enqueue(QueueType *q, int item)
{
    if (IsFull(q))
        return;

    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->items[q->rear] = item;
    q->count++;
}

int Dequeue(QueueType *q)
{
    if (IsEmpty(q))
        return -1;

    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_VERTICES;
    q->count--;
    return item;
}
