#include <stdio.h>

int d[100], c[100][100], sol[100];
int makechange(int n, int N)
{
    for(int i=0; i<=n; i++)
    {
        c[i][0]=0;
    }
    for(int j=1; j<=N; j++)
    {
        c[0][j]=100;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i==j)
                c[i][j]= 1+c[1][j-d[1]];
            else if(j<d[i])
                c[i][j]=c[i-1][j];
            else
            {
                if( (c[i-1][j]) > (1+c[i][j-d[i]]) )
                    c[i][j]=1+c[i][j-d[i]];
                else
                    c[i][j]=c[i-1][j];
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=N; j++)
        {
            printf("%d\t\t", c[i][j]);
        }
        printf("\n");
    }
    return(c[n][N]);
}

void trace(int n, int N)
{
    int counter=0, i=n, j=N;
    while(j>0)
    {
        if(c[i][j]==c[i-1][j])
            i=i-1;
        else
        {
            j=j-d[i];
            sol[counter++] = d[i];
        }
    }
    printf("Solution:\n");
    for(int i=0; i<counter; i++)
    {
        printf("%d\t", sol[i]);
    }
}

int main(){
    int n , N;
    printf("Enter the Amount: ");
    scanf("%d", &N);
    printf("Enter no. of Denomination: ");
    scanf("%d", &n);
    d[0] = 0;
    for(int i=1; i<=n; i++)
    {
        printf("Enter the Denomination: ");
        scanf("%d", &d[i]);
    }   
    makechange(n, N);
    trace(n, N);
    return 0;
}