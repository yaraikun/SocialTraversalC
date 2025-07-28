/**
 * @file queue.h
 * @brief A simple fixed-size integer queue implementation.
 *
 * This file defines a queue data structure tailored for storing integer
 * indices of graph vertices. It is a fundamental component required for the
 * Breadth-First Search (BFS) traversal algorithm, which explores vertices
 * level by level.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"

/**
 * struct QueueTag - A circular queue for storing vertex indices.
 * @items: A static array to hold the integer items (vertex indices).
 * @front: The index of the first element in the queue.
 * @rear:  The index of the last element in the queue.
 * @count: The current number of items in the queue.
 */
typedef struct QueueTag {
    int items[MAX_VERTICES];
    int front;
    int rear;
    int count;
} QueueType;

/**
 * CreateQueue() - Initializes a queue to an empty state.
 * @q: Pointer to the QueueType structure to initialize.
 */
void CreateQueue(QueueType *q);

/**
 * IsEmpty() - Checks if the queue contains no elements.
 * @q: Pointer to the queue.
 *
 * Return: 1 if the queue is empty, 0 otherwise.
 */
int IsEmpty(QueueType *q);

/**
 * IsFull() - Checks if the queue has reached its maximum capacity.
 * @q: Pointer to the queue.
 *
 * Return: 1 if the queue is full, 0 otherwise.
 */
int IsFull(QueueType *q);

/**
 * Enqueue() - Adds an item to the rear of the queue.
 * @q:    Pointer to the queue.
 * @item: The integer item (vertex index) to add.
 */
void Enqueue(QueueType *q, int item);

/**
 * Dequeue() - Removes and returns the item from the front of the queue.
 * @q: Pointer to the queue.
 *
 * Return: The item at the front of the queue.
 */
int Dequeue(QueueType *q);

#endif /* QUEUE_H */
