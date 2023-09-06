#include<stdio.h>

int partition(int a[],int l, int u)
{
    int v=a[l],i=l,j=u+1,temp;
    do
    {
        do
        {
            i++;
        } while (a[i]<v && i<=u);
        do
        {
            j--;
        } while (a[j]>v && j>=l);
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }  
    }while(i<j);
    a[l] = a[j];
    a[j] = v;
    return j;
    
}

void quicksort(int a[100],int l,int u)
{
    int v;
    if(l<u)
    {
        v = partition(a,l,u);
        quicksort(a,l,v-1);
        quicksort(a,v+1,u);
    }
}


int main()
{
    int i;
    int a[] = {35,50,15,25,80,20,90,45};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(a,0,n-1);

    printf("After sorting:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}