#include "queue.h"
#include "graph.h"

/**
 * CreateQueue() - Initializes a queue.
 *
 * @q: Pointer to the queue to initialize.
 *
 * Sets the front and rear indices and count of the queue to their
 * initial values. This function must be called before using the queue.
 */
void CreateQueue(QueueType *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

/**
 * IsEmpty() - Checks if the stack is empty.
 *
 * @q: Pointer to the queue to check.
 *
 * A queue is considered empty if its count is 0.
 *
 * Return: 1 if the stack is empty, 0 otherwise.
 */
int IsEmpty(QueueType *q)
{
    return q->count == 0;
}

/**
 * IsFull() - Checks if the queue has reached its maximum capacity.
 *
 * @q: Pointer to the queue to check.
 *
 * A queue is considered full if its count is equal to the maximum capacity 
 * (MAX_VERTICES).
 *
 * Return: 1 if the stack is full, 0 otherwise.
 */
int IsFull(QueueType *q)
{
    return q->count == MAX_VERTICES;
}

/**
 * Enqueue() - Inserts an item into the queue.
 *
 * @q:    Pointer to the queue.
 * @item: The item to insert.
 *
 * Adds an item to the rear of the queue and increments count if there is space. 
 * If the queue is full, the function returns. Uses circular indexing.
 */
void Enqueue(QueueType *q, int item)
{
    if (IsFull(q))
        return;

    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->items[q->rear] = item;
    q->count++;
}

/**
 * Dequeue() - Removes and returns the front item of the queue.
 *
 * @q: Pointer to the queue.
 *
 * Removes the front item of the queue and returns it. If the queue is empty,
 * returns -1 as an error indicator. Uses circular indexing to update the front.
 *
 * Return: The item at the front of the queue, or -1 if empty.
 */
int Dequeue(QueueType *q)
{
    if (IsEmpty(q))
        return -1;

    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_VERTICES;
    q->count--;
    return item;
}
