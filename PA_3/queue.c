#include "queue.h"

/// Initializes values for new queue
/// @param queue Represents pointer to a queue
void initializeQueue(Queue* queue)
{
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
}

/// Places a new Process* at the end of a queue
/// @param queue Represents pointer to a queue
/// @param data Represents the data being placed in queue
/// @remark Data is a pointer to a Process
void enqueue(Queue* queue, Process* data)
{
    if (queue->size < MAX_QUEUE_SIZE)
    {
        queue->items[queue->tail] = data;
        queue->tail++;
        queue->size++;
        return;
    }

    printf("Queue is full!");
}

/// Removes a Process* at head of a queue
/// @param queue
/// @return Process* that was formally the head of the queue
/// @remark Note that this function removes Process* and returns it
Process* dequeue(Queue* queue)
{
    if (queue->size == 0)
    {
        printf("Empty queue, nothing to remove.");
        return queue->items[queue->head];
    }
    Process *formerHead = queue->items[queue->head]; // save it to return before we shift the head index
    queue->head++;
    queue->size--;
    return formerHead;
}

/// Returns Process* without removing from head of the queue
/// @param queue Represents pointer to a queue
/// @return Represents the Process* at the head of a queue
Process* peek(Queue* queue)
{
    return queue->items[queue->head];
}

/// Returns value representing whether a certain Process* appears in a queue
/// @param queue Represents a pointer to a queue
/// @param target Represents the targeted Process* being searched for
/// @return Integer value representing whether a certain Process* appears in a queue
/// @remark Returns 0 if target is not present, 1 if it is
int is_queued(Queue* queue, Process *target)
{
    for (int i = queue->head; i < queue->head + queue->size; i++)
    {
        if (queue->items[i] == target)
        {
            return 1;
        }
    }

    return 0;
}

/// Sorts elements in the queue based on priority (in this case burst time)
/// @param queue Represents queue being sorted
void priorityQueueSort(Queue* queue)
{
    for (int i = queue->head + 1; i < queue->tail; i++)
    {
        Process* current = queue->items[i];

        int j = i - 1;
        for (; j >= queue->head && queue->items[j]->burst_time > current->burst_time; j--)
        {
            queue->items[j + 1] = queue->items[j];
        }
        queue->items[j + 1] = current;
    }
}

/// Utility function to visualize queue in stdout
/// @param queue Represents queue to be printed
void printQueue(Queue* queue)
{
    if (queue->size == 0)
    {
        return;
    }
    for (int i = queue->head; i < queue->size + queue->head; i++)
    {
        printf("Element: %d PID: %d Arrival: %d Burst: %d \n",
            i, queue->items[i]->pid, queue->items[i]->arrival_time, queue->items[i]->burst_time);
    }
}
