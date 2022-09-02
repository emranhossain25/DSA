#include<stdio.h>

void printARRAY(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void merge(int a[],int mid,int lb,int ub)
{
    int i,j,k,b[100];
    i=lb;
    j=mid+1;
    k=lb;
    while (i<=mid && j<=ub)
    {
        if (a[i]<a[j])
        {
            b[k]=a[k];
            i++;
            k++;
        }
        
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
        
    }
    if (i>mid)
    {
        while (j<=ub)
        {
            b[k]=a[j];
            i++;
            k++;
        }
        
    }
    else
    {
        while (i<=mid)
        {
            b[k]=a[i];
            i++;
            j++;
        }
        
    }
    for ( k = lb; k<=ub; k++)
    {
        a[k]=b[k];
    }
    
}

void mergeSort(int a[],int lb,int ub)
{
    if (lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,mid,lb,ub);
    }
    
}

int main()
{
    int a[100],n;
    printf("enter the size\n");
    scanf("%d",&n);
    printf("now enter %d element oneby one \n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printARRAY(a,n);
    mergeSort(a,0,n);
    printARRAY(a,n);
    
    return 0;
}