#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

 void create()
 {
     struct node *head,*newnode,*ptr;
     head=NULL;
     int choice;
     while (choice)
     {
         newnode=(struct node *)malloc(sizeof(struct node));
         printf("enter the element \n");
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
         
         printf("do you want to continue(0,1)");
         scanf("%d",&choice);
     }
 }

  void traversl()
  {
      struct node *head,*ptr;
      head=ptr;
      while (ptr!=NULL)
      {
          printf("element:%d\n",ptr->data);
          ptr=ptr->next;
      }
      
  }

 void inseratbegin()
 {
     struct node *head, *newnode,*ptr;
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("enter the data which you want to insert\n");
     scanf("%d",&newnode->data);
     newnode->next=head;
     head=newnode;
     
 }

  void insertbetween()
 {
     struct node *head,*newnode,*ptr;
     int i,pos;
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("enter the possition which you to insert\n");
     scanf("%d",&pos);
     while (i<pos)
     {
         ptr=ptr->next;
         i++;
     }
     printf("enter the data\n");
     scanf("%d",&newnode->data);
     newnode->next=ptr->next;
     ptr->next=newnode;

 }
 int main() 
 {
   //  struct node *head;
     create();
     traversl();
//inseratbegin();
insertbetween();
traversl();
//traversl();
     return 0;
 }