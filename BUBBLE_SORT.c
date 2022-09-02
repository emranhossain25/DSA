#include<stdio.h>
#include<stdlib.h>

 void printArray(int arr[],int n)
 {
     for (int  i = 0; i < n; i++)
     {
         printf("%d ",arr[i]);
     }
     printf("\n");
 }

 void bubbleSort(int arr[],int n)
 {
     int temp;
     for (int i = 0; i < n-1; i++)
     {
         for (int j = 0; j < n-1-i; j++)
         {
        if (arr[j]>arr[j+1])
        {
          temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }
                     
         }
         
     }
     printf("\n");
 }

 void BubblesortAdaptive(int *arr,int n)
 {
     int temp;
     int isSorted=0;
     for (int i = 0; i < n-1; i++)
     {
         printf("working on pass number %d\n",i+1);
         isSorted=1;
         for (int  j = 0; j < n-1-i; j++)
         {
             if (arr[j]>arr[j+1])
             {
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
                 isSorted=0;
             }
             
         }
         if (isSorted)
         {
             return;
         }
         
     }
     
 }

 int main()
 {
    int n;
   int arr[100];

   printf("how many element you want to insert\n");
   scanf("%d",&n);
   printf("now enter %d element one by one \n",n);
   for (int  i = 0; i < n; i++)
   {
     scanf("%d",&arr[i]);
   }
   printArray(arr,n);
   BubblesortAdaptive(arr,n);
   printArray(arr,n);
     return 0;
 }