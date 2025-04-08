#include <stdio.h>

int main() {
    int i, n, bt[10], rt[10], time, remain, tq, wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;  // Number of processes left to complete

    for (i = 0; i < n; i++) {
        printf("P[%d] BT: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // Copy burst time to remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Scheduling Loop
    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] > 0 && rt[i] <= tq) {
            time += rt[i];  // Process finishes
            rt[i] = 0;
            remain--;

            tat += time;              // Turnaround time = current time
            wt += time - bt[i];       // Waiting time = TAT - BT
        }
        else if (rt[i] > 0) {
            rt[i] -= tq;  // Process partially runs
            time += tq;
        }

        i = (i + 1) % n;  // Go to next process in a circular way
    }

    printf("Avg WT = %.2f, TAT = %.2f\n", (float)wt / n, (float)tat / n);

    return 0;
}

