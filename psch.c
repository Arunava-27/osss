#include<stdio.h>
#include<stdlib.h>
struct p
{
    int pid;
    int at;
    int bt;
    int pr;
    int wt;
    int tat;
};

int main()
{
    int n;
    

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct p *ps;
    ps=(struct p*) malloc(n * sizeof(struct p));

    for(int i=0; i<n; i++)
    {
        printf("\nProcess %d ",i+1);
        printf("\nArrival Time: ");
        scanf("%d",&ps[i].at);
        printf("\nBurst Time: ");
        scanf("%d",&ps[i].bt);
        printf("\nPriority: ");
        scanf("%d",&ps[i].pr);
        ps[i].pid=i+1;
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ps[j].pr<ps[j+1].pr)
            {
                struct p t = ps[j];
                ps[j]=ps[j+1];
                ps[j+1]=t;
            }
        }
    }

    ps[0].wt=0;
    ps[0].tat=ps[0].bt;
    for(int i=1; i<n;i++)
    {
        ps[i].wt=ps[i-1].tat+(ps[i-1].at-ps[i].at);
        ps[i].tat=ps[i].wt+ps[i].bt;
    }

    float avg_wt=0, avg_tat=0;

    for(int i=1; i<n;i++)
    {
        avg_wt=avg_wt+ps[i].wt;
        avg_tat=avg_tat+ps[i].tat;
    }
    avg_wt/=n;
    avg_tat/=n;

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(int i=0; i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].pr,ps[i].wt,ps[i].tat);

    }
    printf("\nAverage TAT: %f\nAverage WT: %f",avg_tat,avg_wt);
    
    free(ps);

    return 0;
}