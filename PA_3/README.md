


# CptS 360 - PA3
## How to Compile and Run

### Compile program: `gcc -Wall scheduling.c fcfs.c queue.c roundRobin.c sjf.c sort.c -o PA3`

### Run program: `./PA3 processes.txt 2 `

## Assumptions Made

    - Text input files don't have a header line to parse out, simply input separated by spaces
    - Quantum time for round robin provided in command line argument

## Example Input and Output \
#### Some operations performed taken from console output:
```
===== First-Come, First-Serve =====
P1 [0 -> 5]
P2 [5 -> 8]
P3 [8 -> 9]
P4 [9 -> 11]

PID     Arrival Burst   Waiting Turnaround
1       0       5       0       5
2       1       3       4       7
3       2       1       6       7
4       3       2       6       8

Average Waiting Time: 4.00
Average Turnaround Time: 6.75

===== Shortest Job First =====
P1 [0 -> 5]
P3 [5 -> 6]
P4 [6 -> 8]
P2 [8 -> 11]

PID     Arrival Burst   Waiting Turnaround
1       0       5       0       5
2       1       3       7       10
3       2       1       3       4
4       3       2       3       5

Average Waiting Time: 3.25
Average Turnaround Time: 6.00

===== Round Robin (q = 2) =====
P1 [0 -> 2]
P2 [2 -> 4]
P1 [4 -> 6]
P3 [6 -> 7]
P4 [7 -> 9]
P2 [9 -> 10]
P1 [10 -> 11]

PID     Arrival Burst   Waiting Turnaround
1       0       5       6       11
2       1       3       6       9
3       2       1       4       5
4       3       2       4       6

Average Waiting Time: 5.00
Average Turnaround Time: 7.75
```
Some output for different tests:
```
Round Robin tests: 

P1 [0 -> 2]
P2 [2 -> 4]
P1 [4 -> 6]
P3 [6 -> 8]
P2 [8 -> 10]
P3 [10 -> 12]

PID	Arrival	Burst	Waiting	Turnaround
1	0	4	2	6
2	1	4	5	9
3	2	4	6	10

Average Waiting Time: 4.33
Average Turnaround Time: 8.33
---------------------------------------------------------
P1 [0 -> 2]
P2 [2 -> 5]
P3 [5 -> 6]
P2 [6 -> 8]

PID	Arrival	Burst	Waiting	Turnaround
1	0	2	0	2
2	0	5	3	8
3	0	1	5	6

Average Waiting Time: 2.67
Average Turnaround Time: 5.33
---------------------------------------------------------

SJF tests:

P3 [0 -> 1]
P2 [1 -> 4]
P1 [4 -> 10]

PID	Arrival	Burst	Waiting	Turnaround
1	0	6	4	10
2	0	3	1	4
3	0	1	0	1

Average Waiting Time: 1.67
Average Turnaround Time: 5.00
---------------------------------------------------------
P1 [0 -> 5]
P3 [5 -> 6]
P4 [6 -> 8]
P2 [8 -> 11]

PID	Arrival	Burst	Waiting	Turnaround
1	0	5	0	5
2	1	3	7	10
3	2	1	3	4
4	3	2	3	5

Average Waiting Time: 3.25
Average Turnaround Time: 6.00
---------------------------------------------------------
P1 [0 -> 1]
P2 [5 -> 6]
P3 [10 -> 11]

PID	Arrival	Burst	Waiting	Turnaround
1	0	1	0	1
2	5	1	0	1
3	10	1	0	1

Average Waiting Time: 0.00
Average Turnaround Time: 1.00
---------------------------------------------------------
P1 [0 -> 3]
P2 [3 -> 6]
P3 [6 -> 9]

PID	Arrival	Burst	Waiting	Turnaround
1	0	3	0	3
2	0	3	3	6
3	0	3	6	9

Average Waiting Time: 3.00
Average Turnaround Time: 6.00
---------------------------------------------------------

```


