#include<stdio.h>
#include<stdlib.h>

 struct node
 {
     int data;
     struct node *next; 
 };
  void display(struct node *ptr)
     {  
         struct node *head;
         head=ptr;
         while (ptr!=NULL)
     {
     printf("element:%d\n",ptr->data);
     ptr=ptr->next;
     
     }
     }
 int man()
 {
     struct node *head,*newnode,*ptr;
     head=NULL;
     int choice;
     while (choice)
     {
         newnode=(struct node*)malloc(sizeof(struct node));
         printf("enter the element:");
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
 display(head);

     return 0;
 }