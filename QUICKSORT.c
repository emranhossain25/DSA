#include<stdio.h>
#include<stdlib.h>

void printARRAY(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    } while (i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void QuickSort(int arr[],int low,int high)
{
    int partitionindex;
    if (low<high)
    {
        partitionindex = partition(arr,low,high);
        QuickSort(arr,low,partitionindex-1);
        QuickSort(arr,partitionindex+1,high);
    }
    
}
int main()
{
    int arr[100],n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter %d element one by one \n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("BEFORE SORTING\n");
    printARRAY(arr,n);
    printf("AFTER SORTING\n");
    QuickSort(arr,0,n-1);
    printARRAY(arr,n);
}