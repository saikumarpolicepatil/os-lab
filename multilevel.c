#include <stdio.h>

int main()
{
    int i, j, n, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], bt[n], su[n], wt[n], tat[n];

    for (i = 0; i < n; i++)
    {
        pid[i] = i;
        printf("\nEnter the Burst Time of Process-%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("System/User Process (0/1) : ");
        scanf("%d", &su[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (su[i] > su[j])
            {
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = su[i];
                su[i] = su[j];
                su[j] = temp;
            }
        }
    }

    float wtavg, tatavg;
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    for (i = 0; i < n; i++)
    {
        printf("\nProcess-id: %d  System/User Process: %d  Burst Time: %d  Waiting Time: %d  Turnaround Time: %d", pid[i] + 1, su[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time : %0.3f", wtavg / n);
    printf("\nAverage Turnaround Time : %0.3f\n", tatavg / n);

    return 0;
}
