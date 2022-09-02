#include<stdio.h>
#include<stdlib.h>

  struct node

  {
    int data;
    struct node *next;
    
  };
  
  void linklist( struct node *ptr)
  { 
    while (ptr!=NULL)
    {
    printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
    }
    

  }
  int main()
  {

   struct node *head;
   struct node *second;
   struct node *third;
   struct node *forth;
   struct node *fifth;
   struct node *six;
   struct node *seven;
   struct node *eight;
   struct node *nine;
   struct node *teen;

   head = (struct node*)malloc(sizeof(struct node));
   second=(struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));
   forth = (struct node*)malloc(sizeof(struct node));
   fifth = (struct node*)malloc(sizeof(struct node));
   six = (struct node*)malloc(sizeof(struct node));
   seven =(struct node*)malloc(sizeof(struct node));
   eight = (struct node*)malloc(sizeof(struct node));
   nine = (struct node*)malloc(sizeof(struct node));
   teen=(struct node*)malloc(sizeof(struct node));
  
   head->data=2;
   head->next=second;

   second->data=3;
   second->next=third;

   third->data=5;
   third->next=forth;

   forth->data=8;
   forth->next=fifth;

   fifth->data=9;
   fifth->next=six;

   six->data=10;
   six->next=seven;

   seven->data=12;
   seven->next=eight;

   eight->data=15;
   eight->next=nine;

   nine->data=20;
   nine->next=teen;

   teen->data=25;
   teen->next=NULL;

   linklist(head);

      return 0;
  }