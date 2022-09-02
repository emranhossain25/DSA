#include<stdio.h>

void display(int arr[],int size)
{
for(int i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}
printf("\n");

}
int main()
{

int arr[100]={10,15,20,25,30};
int size=5;
display(arr,5);


    return 0;
}
