#include<stdio.h>
void display(int arr[],int size)
{

for (int  i = 0; i <size; i++)
{
printf("%d\n",arr[i]);
}

printf("\n");

}

int insertion(int arr[],int size,int capacity,int index,int element)

{
if (size>=capacity)
{
 return -1;
}

for (int i = size-1; i>=index; i--)
{
    arr[i+1]=arr[i];

}

arr[index]=element;
return 1;

}


int main()
{

int arr[100]={2,5,6,3,4,8};
int size=6, index=3,element=7;

display(arr,size);

insertion(arr,size,100,index,element);
display(arr,size);
return 0;
}
