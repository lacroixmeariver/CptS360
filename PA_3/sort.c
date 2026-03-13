#include "scheduling.h"

/* -----------------------------
   Utility: sort by arrival time
-------------------------------- */
    // TODO:
    // 1. Sort processes by arrival time (if needed)
    // 2. For each process:
    //    - Advance current_time if CPU is idle
    //    - Run process to completion
    //    - Set completion_time

// functions for sorting by arrival time
void quick_arrival_sort(Process processes[], int low, int high)
{
    if (low < high)
    {
        int mid = arrival_partition(processes, low, high);
        quick_arrival_sort(processes, low, mid - 1);
        quick_arrival_sort(processes, mid + 1, high);
    }
}

int arrival_partition(Process processes[], int low, int high)
{
    int i = low;
    int pivot = high - 1;
    int j = pivot;
    const int pivotArrivalTime = processes[pivot].arrival_time;
    while (i < j)
    {
        if (processes[i].arrival_time <= pivotArrivalTime)
        {
            i++;
        }
        else if (processes[j].arrival_time >= pivotArrivalTime)
        {
            j--;
        }

        swap(processes, i, j);
    }
    swap(processes, j, pivot);
    return j;
}

// functions for sorting by burst time
void quick_burst_sort(Process processes[], int low, int high)
{
    if (low < high)
    {
        int mid = burst_partition(processes, low, high);
        quick_burst_sort(processes, low, mid - 1);
        quick_burst_sort(processes, mid + 1, high);
    }
}

int burst_partition(Process processes[], int low, int high)
{
    int i = low;
    int pivot = high - 1;
    int j = pivot;

    const int pivotBurstTime = processes[pivot].burst_time;
    while (i < j)
    {
        if (processes[i].burst_time <= pivotBurstTime)
        {
            i++;
        }
        else if (processes[j].burst_time >= pivotBurstTime)
        {
            j--;
        }

        swap(processes, i, j);
    }
    swap(processes, j, pivot);
    return j;
}

// utility swap function
void swap(Process processes[], int i, int j)
{
    Process temp = processes[i];
    processes[i] = processes [j];
    processes[j] = temp;
}
