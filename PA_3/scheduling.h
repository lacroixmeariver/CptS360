#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

/* -----------------------------
   Process structure
-------------------------------- */
typedef struct {
   int pid;
   int arrival_time;
   int burst_time;

   /* Calculated fields */
   int remaining_time;
   int completion_time;
   int waiting_time;
   int turnaround_time;
} Process;


/* -----------------------------
   Function Prototypes
-------------------------------- */
void swap(Process processes[], int i, int j);
void quick_arrival_sort(Process processes[], int low, int high);
void quick_burst_sort(Process processes[], int low, int high);
int arrival_partition(Process processes[], int low, int high);
int burst_partition(Process processes[], int low, int high);

int read_processes(const char* filename, Process processes[]);
void reset_processes(Process processes[], int n);

void fcfs(Process processes[], int n);
void sjf(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);

void print_metrics(Process processes[], int n);
void print_gantt(int pid, int start, int end);


#endif //SCHEDULING_H
