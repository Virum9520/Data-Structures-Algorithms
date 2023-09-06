#include<stdio.h>

void merge(int a[], int l, int m, int u)
{
    int i=l, j=m+1, k=0, b[100];
    while(i<=m && j<=u)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=u)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=l,k=0;i<=u;i++,k++)
    {
        a[i]=b[k];
    }
}

void mergesort(int a[100],int l, int u)
{
    int m;
    if(l<u)
    {
        m = (l+u)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,u);
        merge(a,l,m,u);
    }
}

int main()
{
    int i;
    int a[] = {6,4,2,1,9,8,3,5};
    int n = sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    printf("After sorting:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
