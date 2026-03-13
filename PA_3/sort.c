#include "scheduling.h"

/* -----------------------------
   Utility: sort by arrival time
-------------------------------- */

/// Sorts processes by arrival time
/// @param processes Represents array of unsorted processes
/// @param low Represents the lowest index of array
/// @param high Represents the highest index of array
/// @remark Function already accounts for highest index being 1 lower than size of array, only size is needed
void quick_arrival_sort(Process processes[], int low, int high)
{
    if (low < high)
    {
        int mid = arrival_partition(processes, low, high - 1);
        quick_arrival_sort(processes, low, mid - 1);
        quick_arrival_sort(processes, mid + 1, high);
    }
}

/// Partitions processes based on arrival time
/// @param processes Represents array of unsorted processes
/// @param low Represents the lowest index of array
/// @param high Represents the highest index of array
int arrival_partition(Process processes[], int low, int high)
{
    int i = low;
    int pivot = high;
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
        else
        {
            swap(processes, i, j);
        }
    }
    if (processes[i].arrival_time > pivotArrivalTime)
    {
        swap(processes, i, pivot);
        return i;
    }

    return pivot;
}


/* -----------------------------
   Utility: sort by burst time
-------------------------------- */

/// Sorts processes by burst time
/// @param processes Represents array of unsorted processes
/// @param low Represents the lowest index of array
/// @param high Represents the highest index of array
/// @remark Function already accounts for highest index being 1 lower than size of array, only size is needed
void quick_burst_sort(Process processes[], int low, int high)
{
    if (low < high)
    {
        int mid = burst_partition(processes, low, high - 1);
        quick_burst_sort(processes, low, mid - 1);
        quick_burst_sort(processes, mid + 1, high);
    }
}

/// Partitions processes based on burst time
/// @param processes Represents array of unsorted processes
/// @param low Represents the lowest index of array
/// @param high Represents the highest index of array
int burst_partition(Process processes[], int low, int high)
{
    int i = low;
    int pivot = high;
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

        else
        {
            swap(processes, i, j);
        }
    }
    if (processes[i].burst_time > pivotBurstTime)
    {
        swap(processes, i, pivot);
        return i;
    }

    return pivot;
}

/// Utility function to swap 2 indices
/// @param processes Represents array of unsorted processes
/// @param i Represents one of the indices being swapped
/// @param j Represents one of the indices being swapped
void swap(Process processes[], int i, int j)
{
    const Process temp = processes[i];
    processes[i] = processes [j];
    processes[j] = temp;
}
