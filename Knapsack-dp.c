#include<stdio.h>

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

int main()
{
    int m=6, n=3;
    int p[] = {1,2,4}, wt[]={2,3,3};
    int matrix[n][m+1];
    for (int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) matrix[i][j] =0;
            else if (wt[i]<=j)
            {
                matrix[i][j] = max(p[i]+matrix[i-1][j-wt[i]], matrix[i-1][j]);
            }
            else
            {
                matrix[i][j] = matrix[i-1][j]; 
            }
        }
    }
    printf("\n");
    // printf("The table is\n");
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         printf("%d",matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(matrix[i][j]==matrix[i-1][j])
        {
            i--;
        }
        else{
            printf("%d\t",wt[i]);
            j=j-wt[i];
            i--;
        }
    }
    return 0;
}