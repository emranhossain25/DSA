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

void SELECTIONSORT(int arr[],int n)
{
    int indexofmin,temp;
    printf("Running selection sort....\n");
    for (int i = 0; i < n-1; i++)
    {
        indexofmin=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[indexofmin])
            {
                indexofmin=j;
            }
            
        }
        temp=arr[i];
        arr[i]=arr[indexofmin];
        arr[indexofmin]=temp;
    }
    
}

int main()
{
    int arr[100],n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("Now enter %d element one by one \n",n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("BEFORE SORTING\n");
    printARRAY(arr,n);
    printf("AFTER SORTING\n");
    SELECTIONSORT(arr,n);
    printARRAY(arr,n);
    return 0;
}