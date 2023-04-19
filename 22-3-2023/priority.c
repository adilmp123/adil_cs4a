#include <stdio.h>
#include <stdbool.h>

#define MAX_processES 10

struct process
{
    int id;
    int bt;
    int priority;
    int at;
    int rt;
};

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(struct process processes[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].priority > processes[j + 1].priority)
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main()
{
    int i, n;
    struct process processes[MAX_processES];
    bool done[MAX_processES] = {false};
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time, burst time and priority of process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].at, &processes[i].bt, &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].rt = processes[i].bt;
    }

    while (true)
    {
        int min_priority_index = -1;
        int min_priority = 99999;

        for (i = 0; i < n; i++)
        {
            if (processes[i].at <= current_time && !done[i] && processes[i].priority < min_priority && processes[i].rt > 0)
            {
                min_priority = processes[i].priority;
                min_priority_index = i;
            }
        }
        
        if (min_priority_index == -1)
        {
            current_time++;
            continue;
        }

        processes[min_priority_index].rt--;
        current_time++;

        if (processes[min_priority_index].rt == 0)
        {
            done[min_priority_index] = true;
            int waiting_time = current_time - processes[min_priority_index].bt - processes[min_priority_index].at;
            total_waiting_time += waiting_time;
            int turnaround_time = current_time - processes[min_priority_index].at;
            total_turnaround_time += turnaround_time;
        }

        if (done[n - 1])
        {
            break;
        }
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("Average waiting time: %0.2f\n", average_waiting_time);
    printf("Average turnaround time: %0.2f\n", average_turnaround_time);

    return 0;
}