#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int pid[100], at[100], bt[100];
    int wt[100], tat[100];

    for (int i = 0; i < n; i++) {
        char pname[20];
        scanf("%s %d %d", pname, &at[i], &bt[i]);
        pid[i] = atoi(pname + 1);
    }

    int current_time = 0;

    for (int i = 0; i < n; i++) {

        if (current_time < at[i])
            current_time = at[i];

        wt[i] = current_time - at[i];
        tat[i] = wt[i] + bt[i];

        current_time += bt[i];
    }

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++)
        printf("P%d %d\n", pid[i], wt[i]);

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++)
        printf("P%d %d\n", pid[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f", avgTAT);

    return 0;
}
