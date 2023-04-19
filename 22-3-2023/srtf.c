#include <stdio.h>
typedef struct
{
        int id, at, bt, ct, tat, wt, rt;
} process;
int main()
{
        int n, currentTime = 0;
        float avgTAT, avgWT;
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        process a[n];
        printf("Enter the id,  arrival time and burst time of n processes: \n");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &a[i].id);
                scanf("%d", &a[i].at);
                scanf("%d", &a[i].bt);
                a[i].rt = a[i].bt;
        }
        int completed = 0;
        int totalWT = 0;
        int totalTAT = 0;
        while (completed < n)
        {
                int sJob = -1;
                int sTime = 99999;
                for (int i = 0; i < n; i++)
                {
                        if (a[i].at <= currentTime && a[i].rt < sTime && a[i].rt > 0)
                        {
                                sJob = i;
                                sTime = a[i].rt;
                        }
                }
                if (sJob == -1)
                {
                        currentTime++;
                }
                else
                {
                        a[sJob].rt--;
                        currentTime++;
                        if (a[sJob].rt == 0)
                        {
                                completed++;
                                a[sJob].ct = currentTime;
                                a[sJob].tat = currentTime - a[sJob].at;
                                a[sJob].wt = a[sJob].tat - a[sJob].bt;
                                totalTAT += a[sJob].tat;
                                totalWT += a[sJob].wt;
                        }
                }
        }
        avgTAT = (float)totalTAT / n;
        avgWT = (float)totalWT / n;
        printf("\nID\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++)
        {
                printf("\nP%d\t%d\t%d\t%d\t%d\t%d", a[i].id, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
        }
        printf("\nAverage Waiting Time = %f", avgWT);
        printf("\nAverage Turn Around Time = %f\n", avgTAT);
}
