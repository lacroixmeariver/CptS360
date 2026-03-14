#include "queue.h"
#include "scheduling.h"

/* -----------------------------
   Round Robin Scheduling
-------------------------------- */
/// Executes processes in phases according to quantum value
/// @param processes Represents array of processes
/// @param n Represents the size of process array
/// @param quantum Represents the time increment in which processes get executed
void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;

    Queue readyQueue;
    initializeQueue(&readyQueue);

    // iterating through and queuing all processes that come in at time = 0
    for (int i = 0; i < n; i++)
    {
        if (processes[i].remaining_time > 0 && processes[i].arrival_time == current_time)
        {
            enqueue(&readyQueue, &processes[i]);
        }
    }

    while (completed < n) {
        int did_work = 0;

        if (readyQueue.size > 0)
        {
            // taking from the head of the queue
            Process* queuedProcess = dequeue(&readyQueue);
            int exec = (queuedProcess->remaining_time > quantum) ? quantum : queuedProcess->remaining_time;

            // logging times
            int start = current_time;
            current_time += exec;
            int end = current_time;

            // displaying info
            print_gantt(queuedProcess->pid, start, end);
            queuedProcess->remaining_time -= exec;
            did_work = 1;

            for (int i = 0; i < n; i++)
            {
                // only queues another process from the original process array IF:
                // Process has remaining time AND has already arrived AND is not already in the queue
                // AND is not the process currently being evaluated
                if (processes[i].remaining_time > 0 && processes[i].arrival_time < current_time &&
                    !is_queued(&readyQueue, &processes[i]) && processes[i].pid != queuedProcess->pid)
                {
                    enqueue(&readyQueue, &processes[i]);
                }
            }

            // if there's time remaining on the process being currently executed let's put it back in the queue
            if (queuedProcess->remaining_time > 0)
            {
                enqueue(&readyQueue, queuedProcess);
            }
            else // if time is not above 0 that means it's done
            {
                queuedProcess->completion_time = current_time;
                completed++;
            }
        }

        if (!did_work) {
            current_time++; // CPU idle
            // queueing up any processes that happen to have arrived after idle time and is not already queued up
            for (int i = 0; i < n; i++)
            {
                if (processes[i].remaining_time > 0 && processes[i].arrival_time < current_time &&
                    !is_queued(&readyQueue, &processes[i]))
                {
                    enqueue(&readyQueue, &processes[i]);
                }
            }
        }
    }
}
