#include<stdio.h>

void sortActivities(int act[],int start[], int finish[], int n)
{
     int i, j, temp;
     for(i = 0; i < n-1; i++)
     {
     for(j = i+1; j < n; j++)
     {
        if(finish[i] > finish[j])
        {
            temp = finish[i];
            finish[i] = finish[j];
            finish[j] = temp;
            temp = start[i];
            start[i] = start[j];
            start[j] = temp;
            temp = act[i];
            act[i] = act[j];
            act[j] = temp;

        }
     }
     }
     printf("Sorted array is:\n");
     for(i=0;i<n;i++)
     {
        printf("\n%d  | %d  | A%d\n", start[i], finish[i], act[i]);
     }
}
void printMaxActivities(int act[],int start[], int finish[], int n)
{
    int i, j;
    i = 0;
    printf("\nFollowing activities are selected:\n");
    
    for(j = 1; j < n; j++)
    {
    if(start[j] >= finish[i])
    {
        printf("A%d",act[j]);
        printf("(%d, %d) ", start[j], finish[j]);
        i = j;
    }
    }
}
int main() {
     int start[] = {5,1,3,0,5,8};
     int finish[] = {9,2,4,6,7,9};
     int act[] = {1,2,3,4,5,6};
     int n = sizeof(start)/sizeof(start[0]);
     sortActivities(act, start, finish, n);
     printMaxActivities(act, start, finish, n);
     return 0;
}