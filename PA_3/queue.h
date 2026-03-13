#ifndef QUEUE_H
#define QUEUE_H
#include "scheduling.h"
#define MAX_QUEUE_SIZE 200

// Defining structure of Queue
typedef struct
{
    Process* items[MAX_QUEUE_SIZE]; // made up of pointers to Processes
    int size;
    int head;
    int tail;

} Queue;

// Function prototypes
void initializeQueue(Queue* queue);
void enqueue(Queue*, Process* data);
Process* dequeue(Queue* queue);
Process* peek(Queue* queue);
int is_queued(Queue* queue, Process *target);

#endif //QUEUE_H
