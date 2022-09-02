#include<stdio.h>
 
 int main()
 {
    int arr[10] [10],r,c,sum=0;
     printf("enter the number of row\n");
     scanf("%d",&r);
     printf("enter the number of coloms\n");
     scanf("%d",&c);
     printf("enter the matrix\n");
     for ( int i = 0; i < r; i++)
     {
     for (int  j = 0; j < c; j++)
     {

     printf(" enter arr[%d][%d] value\n",i,j);
     scanf("%d",&arr[i][j]);
  
     }
     }
     
     printf("diogonal matrix are\n");
     
     if (r==c)
     {
     for (int i = 0; i < r; i++)
     {
     for (int j = 0; i < c; j++)
     {    
      if (i==j)
      {
      printf("%d\n",arr[i][j]);
      sum=sum+arr[i][j];
      }
     else
     printf("\n");
     } 
     }
     }
    printf("sum=%d",sum);     

     return 0;
 }