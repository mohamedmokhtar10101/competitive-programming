#include<stdlib.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef int QueueElement;
//#define Queue_array_Based
#define MAXQUEUE 100
#ifdef Queue_array_Based
typedef struct queue
{
int front;
int rear;
int size;
QueueElement arr[MAXQUEUE];
} Queue;
void initializeQueue(Queue * pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void append(QueueElement e , Queue * pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->arr[ pq->rear ] = e;
    pq->size ++;
}
QueueElement serve(Queue * pq)
{
    QueueElement e = pq->arr[ pq->front ];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
    return e;
}
int queueEmpty(Queue * pq)
{
    return !pq->size;
}
int queueFull(Queue * pq)
{
    return pq->size == MAXQUEUE;
}
int queueSize(Queue * pq)
{
    return pq->size;
}
void clearQueue(Queue * pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void traverseQueue(Queue * pq , void (*display)(QueueElement))
{
int i;
int begin;
for(begin = pq->front , i = 0;i < pq->size; i++,begin = (begin +1) % MAXQUEUE)
        (*display)(pq->arr[ begin ]);
}
#else
typedef struct QueueNode
{
QueueElement e;
struct QueueNode * next;
} QueueNode;
typedef struct Queue
{
    QueueNode * front;
    QueueNode * rear;
    int size;
} Queue;
void initializeQueue(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void append(QueueElement e , Queue * pq)
{
    QueueNode * pNewNode = malloc(sizeof(QueueNode));
    pNewNode->e = e;
    pNewNode->next = NULL;
    if(pq->front == NULL)
        pq->front = pNewNode;
    else
        pq->rear->next = pNewNode;
    pq->rear = pNewNode;
    pq->size ++;
}
QueueElement serve(Queue * pq)
{
    QueueElement e = pq->front->e;
    QueueNode * tmp = pq->front;
    pq->front = pq->front->next;
    free(tmp);
    if(pq->front == NULL)
        pq->rear = NULL;
    pq->size--;
    return e;
}
int queueEmpty(Queue * pq)
{
    return !pq->size;
}
int queueFull(Queue * pq)
{
    return 0;
}
int queueSize(Queue * pq)
{
    return pq->size;
}
void clearQueue(Queue * pq)
{
 while(pq->front != NULL)
 {
     pq->rear = pq->front->next;
     free(pq->front);
     pq->front = pq->rear;
 }
 pq->size = 0;
}
void traverseQueue(Queue * pq , void (*display)(QueueElement))
{
QueueNode * begin;
for(begin = pq->front ;begin != NULL;begin = begin->next)
        (*display)(begin->e);
}
#endif // Queue_array_Based
#endif // QUEUE_H_INCLUDED
