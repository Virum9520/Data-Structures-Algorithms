#include <stdio.h>

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Function to perform job scheduling
void scheduleJobs(struct Job jobs[], int n) {
    // Sort the jobs based on their profit in non-increasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // Array to store the result (scheduled jobs)
    char result[n];
    int slots[n];

    // Initialize slots array with 0
    for (int i = 0; i < n; i++) {
        slots[i] = 0;
    }

    // Fill the result array by scheduling jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                result[j] = jobs[i].id;
                slots[j] = 1;
                break;
            }
        }
    }

    // Calculate the total profit and print the scheduled jobs
    int totalProfit = 0;
    printf("Scheduled jobs: ");
    for (int i = 0; i < n; i++) {
        if (slots[i] == 1) {
            printf("%c ", result[i]);
            totalProfit += jobs[i].profit;
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

// Test the job scheduling algorithm
int main() {
    // Array of jobs (id, deadline, profit)
    struct Job jobs[] = { {'1', 5, 200}, {'2', 3, 180}, {'3', 3, 190},
                          {'4', 2, 300}, {'5', 4, 120}, {'6', 2, 100} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    scheduleJobs(jobs, n);

    return 0;
}
