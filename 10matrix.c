#include<stdio.h>

int main()
{
int arr[10][10],r,c,sum1=0,sum2=0;
  printf("enter the number of row\n");
  scanf("%d",&r);
  printf("enter the number of coloms\n");
  scanf("%d",&c);
  for (int  i = 0; i <r; i++)
  {
  for (int j = 0; j < c; j++)
  {
  printf("enter arr[%d][%d] value\n",i,j); 
    scanf("%d",&arr[i][j]);
  }
  
  }
  for (int i = 0; i < r; i++)
  {
  for (int j = 0; j < c; j++)
  {
  
   if (j>i)
 {
 sum1=sum1+arr[i][j];
 }

 else
 if (i>j)
 {
sum2=sum2+arr[i][j];
 }
  }
  }

  printf("sum of avube diogonal element=%d\n",sum1);
  printf("sum of below diogonal element=%d\n",sum2);
  printf("total sum=%d\n",sum1+sum2);
return 0;
}