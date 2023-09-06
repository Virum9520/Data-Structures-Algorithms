#include<stdio.h>
int n=6;
int p[6]={4,10,3,12,20,7};
int M[20][20];
int karr[20][20];

int MandM(int i, int j)
{
  int k,sum;
  int min=999;
  int mink;

  if(i==j)
  {
    mink=i;
    return 0;
  }

  for(k=i;k<j;k++)
  {
     sum = MandM(i,k) + MandM(k+1,j) + (p[i-1]*p[k]*p[j]);
     if(sum<min)
     {
       min=sum;
       mink=k;
     }
  }

  karr[i][j]=mink;
  return min;
}
// void print_para(int i,int j)
// {
//   if(i==j)
//   {
//     printf("A%d",i);
//   }
//   else
//   {
//     printf("(");
//     print_para(i,karr[i][j]);
//     print_para(karr[i][j]+1,j);
//     printf(")");
//   }
// }

int main()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
       M[i][j] = MandM(i,j);
    }
  }
  printf("Matrix\n");
  for(i=1;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
      printf("%d ",M[i][j]);
    }
    printf("\n");
  }
  printf("Minimum K Matrix\n");
  for(i=1;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
      printf("%d ",karr[i][j]);
    }
    printf("\n");
  }
  // print_para(1,n-1);
  // printf("\n");
  return 0;
}