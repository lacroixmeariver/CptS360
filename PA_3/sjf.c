#include "scheduling.h"

/* -----------------------------
SJF Scheduling (Non-preemptive)
-------------------------------- */
void sjf(Process processes[], int n) {

    // TODO:
    // 1. While not all processes are completed:
    // 2. Find the available process with the shortest burst time
    // 3. Execute it fully and update completion_time
    // 4. Handle CPU idle time if no process is available

    quick_arrival_sort(processes, 0, n);

    int current_time = processes[0].burst_time; // has no choice since it's non-preemptive
    print_gantt(processes[0].pid, 0, current_time);
    processes[0].completion_time = current_time;

    // the processes come in sorted by time, all iterations represent the time
    for (int i = 1; i < n; i++)
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

