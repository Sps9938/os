#include <stdio.h>
int main() {
    int n, bt[20], p[20], pr[20], wt[20], tat[20], i, j, temp; float avg_wt=0, avg_tat=0;
    printf("Enter number of processes: "); scanf("%d", &n);
    for (i = 0; i < n; i++) { printf("P[%d] BT: ", i+1); scanf("%d", &bt[i]); printf("Priority: "); scanf("%d", &pr[i]); p[i] = i+1; }
    for (i = 0; i < n; i++) for (j = i+1; j < n; j++) if (pr[i] > pr[j]) {
        temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
        temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
        temp=p[i]; p[i]=p[j]; p[j]=temp;
    }
    wt[0]=0;
    for (i=1;i<n;i++) { wt[i]=0; for(j=0;j<i;j++) wt[i]+=bt[j]; }
    for(i=0;i<n;i++) { tat[i]=bt[i]+wt[i]; avg_wt+=wt[i]; avg_tat+=tat[i]; }
    for(i=0;i<n;i++) printf("P[%d]\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    printf("Avg WT=%.2f, TAT=%.2f\n", avg_wt/n, avg_tat/n); return 0;
}
