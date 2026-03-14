#include "scheduling.h"

/* -----------------------------
   FCFS Scheduling
-------------------------------- */

/// Executes processes in a FIFO order
/// @param processes Represents the array of processes
/// @param n Represents the size of process array
void fcfs(Process processes[], int n) {

    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        int start = current_time;
        current_time += processes[i].burst_time;
        int end = current_time;

        print_gantt(processes[i].pid, start, end);
        processes[i].completion_time = end;
    }
}
