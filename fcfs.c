#include<stdio.h>

struct Process {
	int pid;
	int at;
	int bt;
	int tat;
	int wt;
	int ct;
};

void fcfsCpuSchedulling()
{

int n,i,j;
struct Process p[20];
struct Process temp;
float avg_tat = 0, avg_wt = 0;

printf("Enter the number of processes: ");
scanf("%d", &n);

for (i=0;i<n;i++){
p[i].pid = i+1;
printf("Enter Arrival Time and Brust Time for Process %d ", i+1);
scanf("%d %d", &p[i].at, &p[i].bt);

}
//sort by Arrival time
for (i=0;i<n-1;i++)
{
	for (j=i+1;j<n;j++)
	{
		if(p[i].at > p[j].at){
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}

	}

}

//schedulling logic
int current_time = 0;
for (i=0;i<n;i++)
{
	if(current_time < p[i].at)
		current_time = p[i].at;

	p[i].ct = current_time + p[i].bt;
	p[i].tat = p[i].ct - p[i].at;
	p[i].wt =  p[i].tat - p[i].bt;
	
	current_time = p[i].ct;
	
	avg_tat += p[i].tat;
	avg_wt += p[i].wt;
}
	avg_tat /= n;
	avg_wt /= n;
	
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
	printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

}

	printf("\nAverage TurnAround Time: %.2f", avg_tat);
	printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}
int main()
{
	fcfsCpuSchedulling();
	return 0;
}
