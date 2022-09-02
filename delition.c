#include<stdio.h>

void display(int arr[],int size)
{

for (int i = 0; i < size; i++)
{
    printf("%d\n",arr[i]);
}

printf("\n");

}

void delition(int arr[],int size,int index)

{

for (int i = index; i < size-1; i++)
{
arr[i]=arr[i+1];
}

}

int main()
{

int arr[100],index,size;

printf("how many element you want to insert\n");

scanf("%d",&size);

    printf("now enter %d element one by one\n",size);

for (int i = 0; i < size; i++)
{
    scanf("%d",&arr[i]);
}

printf("now enter the index which you want to delete\n");

scanf("%d",&index);
display(arr,size);
 printf("\n");
delition(arr,size,index);
   
   size-=1;
   display(arr,size);
   
    return 0;
}