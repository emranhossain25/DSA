//WAP INSERTION(BEGINNIN,BETWEEN,END)
#include<stdio.h>
#include<stdlib.h>

 struct node 
 {
     int data;
     struct node *next;
 };
 
  void traversal(struct node *ptr)
 {
     struct node *head=ptr;
      while (ptr!=NULL)
      {
          printf("ELEMENT:%d\n",ptr->data);
          ptr=ptr->next;
      }
      
  }

  struct node * insertatbegin(struct node *head)
{
      struct node *newnode,*ptr;
      newnode=(struct node *)malloc(sizeof(struct node));
      printf("enter the data which yo want to insert\n");
      scanf("%d",&newnode->data);
      newnode->next=head;
      head=newnode;
      return head;
  } 

  struct node * insertinbetween(struct node * head)
  {
    struct node *newnode,*ptr;
    int i,pos;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("enter the possition\n");
  scanf("%d",&pos);
  ptr=head;
  while (i<pos)
  {
      ptr=ptr->next;
      i++;
  }
   printf("enter the data\n");
   scanf("%d",&newnode->data);
  newnode->next=ptr->next;
   ptr->next=newnode;
   return head;
  }

  struct node * insertatend(struct node *head)
  {
      struct node *newnode,*ptr;
      newnode=(struct node*)malloc(sizeof(struct node));
      printf("enter the data\n");
      scanf("%d",&newnode->data);
      ptr=head;
      while (ptr->next!=NULL)
      {
          ptr=ptr->next;
      }
      ptr->next=newnode;
      newnode->next=NULL;
      return head;
  }

  int main()
  {
      struct node *head,*newnode,*ptr;
      int choice1,choice2,count=0;
      head=NULL;
      while (choice1)
      {
      newnode=(struct node *)malloc(sizeof(struct node));
      printf("enter the element\n");
      scanf("%d",&newnode->data);
      newnode->next=NULL;
      if (head==NULL)
       {
           head=ptr=newnode;
       }
       else
       {
           ptr->next=newnode;
           ptr=newnode;
       }
       printf("do you want to continue:(0,1)");
       scanf("%d",&choice1);
      }
      printf("BEFORE INSERTION\n");
      traversal(head);
      printf("AFTER INSERTION\n");
      printf("enter your choice2\n:1:insertatbegin\n,2:insertatbetween\n,3:insertatend\n,4:exit\n");
      while (choice2!=4)
      {
          printf("enter your choice2\n");
          scanf("%d",&choice2);
          switch (choice2)
          {
          case 1:
          {
              head=insertatbegin(head);
              traversal(head);
              break;
          }
          case 2:
          {
              head=insertinbetween(head);
              traversal(head);
              break;
          }
          case 3:
          {
              head=insertatend(head);
              traversal(head);
              break;
          }
          case 4:
          {
              printf("exit");
              break;
          }
          default:
          printf("invalid input");
              break;
          }
      }
      
   return 0;
  }