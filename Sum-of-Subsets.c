#include <stdio.h>

void generateSubsets(int set[], int n, int sum, int currentSum, int subset[], int subsetSize, int index) {
 if (currentSum == sum) {

 printf("Subset with sum %d: ", sum);
 for (int i = 0; i < subsetSize; i++) {
 printf("%d ", subset[i]);
 }
 printf("\n");
 return;
 }

 if (index == n || currentSum > sum) {
 return;
 }
 subset[subsetSize] = set[index];
 generateSubsets(set, n, sum, currentSum + set[index], subset, subsetSize + 1, index + 1);
 generateSubsets(set, n, sum, currentSum, subset, subsetSize, index + 1);
}

void findAllSubsets(int set[], int n, int sum) {
 int subset[n];
 generateSubsets(set, n, sum, 0, subset, 0, 0);
}

int main() {
 int set[] = {2,3,5,6,8,10};
 int n = sizeof(set) / sizeof(set[0]);
 int sum = 10;

 findAllSubsets(set, n, sum);

 return 0;
}