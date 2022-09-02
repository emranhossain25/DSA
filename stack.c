#include<stdio.h>

int stack[100];
int choice;
int size;
int val;
int top;
void push()
{

if (top==size-1)
{
printf("stack overflow cannot push any element\n");
}

else
{
printf("enter the value which you want to pushed\n");

scanf("%d",&val);
top++;
stack[top]=val;

}

}


void pop()
{

if (top==-1)
{
printf("stack underflow cannot popped any element\n");
}

else
{

printf("poped element is %d\n",stack[top]);

top--;

}

}

void display()
{

if (top>=0)
{
  printf("the element present in stack\n");

for (int  i = top; i>=0; i--)
{
    printf("%d\n",stack[i]);
}
  printf("press next choice\n");
}

else
{

printf("the stack is empty\n");

}
}

int main()
{

top=-1;
printf("enter the size of stack\n");
scanf("%d",&size);
printf("press 1:push\n,2:pop\n,3:display\n,4:exit\n");

while (choice!=4)
{
 printf("enter your choice\n ");
 scanf("%d",&choice); 
switch (choice)
{
case 1:
{
push();
  break;
}

case 2:
{
pop();
break;
}

case 3:
{
display();
break;

}

case 4:
{

  printf("exit");
  break;
}

}

}
    return 0;
}