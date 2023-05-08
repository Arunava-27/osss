#include <stdio.h>

int main() {
    int n, quantum, rem_bt[10], wt[10], tat[10], total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];
    printf("Enter the burst time for each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int t = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == 1)
            break;
    }

    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

  
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("Average Waiting Time: %f\n", (float)total_wt/n);
    printf("Average Turnaround Time: %f\n", (float)total_tat/n);

    return 0;
}
