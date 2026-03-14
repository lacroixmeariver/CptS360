#include "queue.h"
#include "scheduling.h"

/* -----------------------------
SJF Scheduling (Non-preemptive)
-------------------------------- */

/// Executes processes in order of shortest job first
/// @param processes Represents the array of processes
/// @param n Represents the size (in elements) of the process array
void sjf(Process processes[], const int n) {
    // non-preemptive sjf: process doesn't stop to accommodate for shorter burst times as they come in
    // once a process is in, it's getting executed till it's done

    int completed = 0;
    int current_time = 0;

    Queue readyQueue;
    initializeQueue(&readyQueue);

    // all processes under or at the current time get queued
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time <= current_time)
        {
            enqueue(&readyQueue, &processes[i]);
        }
    }

    // queued elements are sorted by burst time
    priorityQueueSort(&readyQueue);

    while (completed < n)
    {
        int did_work = 0;
        if (readyQueue.size > 0)
        {
            Process* queuedProcess = dequeue(&readyQueue);

            int start = current_time;
            current_time += queuedProcess->burst_time;
            int end = current_time;

            print_gantt(queuedProcess->pid, start, end);
            queuedProcess->completion_time = end;
            completed++;
            did_work = 1;

            // queuing the processes that have come in since the execution of the queued process
            for (int j = 0; j < n; j++)
            {
                if (processes[j].arrival_time < current_time &&
                    processes[j].completion_time == 0 &&
                    !is_queued(&readyQueue, &processes[j]) &&
                    processes[j].pid != queuedProcess->pid)
                {
                    enqueue(&readyQueue, &processes[j]);
                }
            }
            // making sure queue is sorted again in respect to burst time
            priorityQueueSort(&readyQueue);
        }

        if (!did_work) {
            current_time++; // CPU idle
            for (int k = 0; k < n; k++) // making sure to queue whatever came in while idle
            {
                if (processes[k].arrival_time <= current_time &&
                    processes[k].completion_time == 0 &&
                    !is_queued(&readyQueue, &processes[k]))
                {
                    enqueue(&readyQueue, &processes[k]);
                }
            }
        }
    }
}

