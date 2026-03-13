#include "scheduling.h"

/* -----------------------------
SJF Scheduling (Non-preemptive)
-------------------------------- */

/// Executes processes in order of shortest job first
/// @param processes Represents the array of processes
/// @param n Represents the size (in elements) of the process array
void sjf(Process processes[], const int n) {

    // TODO: Stress testing for unusual/edge cases to see if this thing will hold up

    // preemptive: process doesn't stop to accommodate for shorter burst times
    // once a process is in, it's getting executed till it's done

    // take the first element in order of arrival and execute it
    int current_time = processes[0].burst_time;
    print_gantt(processes[0].pid, 0, current_time);
    processes[0].completion_time = current_time; // setting the current time accordingly

    for (int i = 1; i < n; i++) // starting at the second index now
    {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        quick_burst_sort(processes, i, n);
        int start = current_time;
        current_time += processes[i].burst_time;
        int end = current_time;
        print_gantt(processes[i].pid, start, end);
        processes[i].completion_time = end;
    }
}

