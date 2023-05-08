#include <stdio.h>

int main() {
    int n, at[10], bt[10], wt[10], tat[10], ct[10], total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time for each process:\n");
    for(int i = 0; i < n; i++)
        scanf("%d %d", &at[i], &bt[i]);

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j+1]) {
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    tat[0] = bt[0];
    wt[0] = 0;
    total_wt = wt[0];
    total_tat = tat[0];

    for(int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];
        if(wt[i] < 0)
            wt[i] = 0;

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i], ct[i]);

    printf("Average Waiting Time: %f\n", (float)total_wt/n);
    printf("Average Turnaround Time: %f\n", (float)total_tat/n);

    return 0;
}
