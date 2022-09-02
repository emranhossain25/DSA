#include<stdio.h>
#include<conio.h>
#define size 10

   int queue[size],front=-1,rear=-1;
  void enqueue(int value)
  {
   if (rear=size-1)
   {
    printf("queue is full\n");
   }
  else
  if (front==-1)
  {
    front=0;
    rear++;
    queue[rear]=value;
    printf("insertion succcesfully\n");
  }
  
  }

  void dequeue()
  {
  if (front==rear)
  {
    printf("queue is empty\n");
  }
  else
  {
  printf("deleted element:%d\n",queue[front]);
  front++;
  if (front==rear)
  {
    front=rear=-1;
  }
  
  }
  }
  void display()
  {
  if (rear==-1)
  {
   printf("queue is empty\n");
  }
 else
 {
   printf("queue element are:\n");
   for (int i = front; i <=rear; i++)
   {
    printf("%d\n",queue[i]);
   }
     
 }
 }
  
  int main()
  { 
 int value,choice; 
 
 printf("1.insertion\n 2.deletion\n 3.display\n 4.exit\n");
 while(1)
 {
 printf("enter your choice\n");
 scanf("%d",&choice);
 switch (choice)
 {
 case 1:
  {
    printf("enter the value to be insert\n");
    scanf("%d",&value);
     break;
  }
 case 2:
 {
 dequeue();
 break;
 }
 case 3:
 {
     display();
     break;
 }
 case 4:
 {
printf("exit\n");
break;
 }
 }

 }
   return 0;   
  }