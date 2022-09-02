#include<stdio.h>

int main()
{
int arr[100],size;

printf("how many elementyou want to store\n");

scanf("%d",&size);
printf("now entered %d one by one \n",size);

for (int i = 0; i <size; i++)
{
scanf("%d",&arr[i]);

}

printf("reverse element are\n");

for (int j = size; j >=0; j--)
{
    printf("%d\n",arr[j]);
}

    return 0;
}