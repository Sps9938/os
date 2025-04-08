#include <stdio.h>
int main() {
    int i, n, bt[10], rt[10], time, remain, tq, wt = 0, tat = 0;
    printf("Enter number of processes: "); scanf("%d", &n); remain = n;
    for (i = 0; i < n; i++) { printf("P[%d] BT: ", i+1); scanf("%d", &bt[i]); rt[i] = bt[i]; }
    printf("Enter Time Quantum: "); scanf("%d", &tq);
    for (time=0, i=0; remain!=0;) {
        if (rt[i] > 0 && rt[i] <= tq) { time += rt[i]; rt[i] = 0; remain--; tat += time; wt += time - bt[i]; }
        else if (rt[i] > 0) { rt[i] -= tq; time += tq; }
        i = (i+1)%n;
    }
    printf("Avg WT = %.2f, TAT = %.2f\n", (float)wt/n, (float)tat/n);
    return 0;
}
