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

 void INSERTIONSORT(int arr[],int n)
 {
     int key,j;
     for (int i = 1; i <=n-1; i++)
     {
         key=arr[i];
         j=i-1;
         while (j>=0 && arr[j]>key)
         {
             arr[j+1]=arr[j];
             j--;
         }
         arr[j+1]=key;
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
   printf("BEFORE SORTING\n");
   printArray(arr,n);
   printf("AFTER SORTING \n");
   INSERTIONSORT(arr,n);
   printArray(arr,n);
     return 0;
 }