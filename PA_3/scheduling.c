#include "scheduling.h"

/* -----------------------------
   Main
-------------------------------- */
int main(int argc, char* argv[]) {
    Process processes[MAX_PROCESSES];
    int n;

    if (argc < 3) {
        printf("Usage: %s <input_file> <time_quantum>\n", argv[0]);
        return 1;
    }

    int quantum = atoi(argv[2]);

    n = read_processes(argv[1], processes);
    if (n <= 0) {
        printf("No processes loaded.\n");
        return 1;
    }

    // all processes get sorted by arrival on the way in as a precaution
    quick_arrival_sort(processes, 0, n);

    printf("\n===== First-Come, First-Serve =====\n");
    reset_processes(processes, n);
    fcfs(processes, n);
    print_metrics(processes, n);

    quick_arrival_sort(processes, 0, n);

    printf("\n===== Shortest Job First =====\n");
    reset_processes(processes, n);
    sjf(processes, n);
    print_metrics(processes, n);

    quick_arrival_sort(processes, 0, n);

    printf("\n===== Round Robin (q = %d) =====\n", quantum);
    reset_processes(processes, n);
    round_robin(processes, n, quantum);
    print_metrics(processes, n);

    return 0;
}

/* -----------------------------
   Read input file
-------------------------------- */
int read_processes(const char* filename, Process processes[]) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    while (fscanf(fp, "%d %d %d",
        &processes[count].pid,
        &processes[count].arrival_time,
        &processes[count].burst_time) == 3) {

        processes[count].remaining_time = processes[count].burst_time;
        count++;
    }

    fclose(fp);
    return count;
}

/* -----------------------------
   Reset calculated fields
-------------------------------- */
void reset_processes(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}


/* -----------------------------
   Print Metrics
-------------------------------- */
void print_metrics(Process processes[], int n) {
    double total_wait = 0;
    double total_turnaround = 0;

    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time =
            processes[i].completion_time - processes[i].arrival_time;

        processes[i].waiting_time =
            processes[i].turnaround_time - processes[i].burst_time;

        total_wait += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround_time;

        printf("%d\t%d\t%d\t%d\t%d\n",
            processes[i].pid,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].waiting_time,
            processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
}

/* -----------------------------
   Gantt Chart Helper
-------------------------------- */
void print_gantt(int pid, int start, int end) {
    printf("P%d [%d -> %d]\n", pid, start, end);
}
