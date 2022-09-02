#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void linkedlisttrvarsal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertionatatfirst(struct node *head,int data)
{
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct node * insertatindex(struct node *head,int data,int index)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    } 
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node * insertatend(struct node * head,int data)
{
    struct node * ptr = (struct  node *)malloc(sizeof(struct node));
    struct node * p = head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
} 

struct node * insertafteranode(struct node *head,struct node * prevnode,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;
    struct node *fifth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    forth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=7;
    third->next=forth;

    forth->data=8;
    forth->next=fifth;

    fifth->data=9;
    fifth->next=NULL;
    printf("before insertion\n");
    linkedlisttrvarsal(head);
  head=insertionatatfirst(head,10);
   //  head=insertatindex(head,60,2);
  // head=insertatend(head,40);
// head=insertafteranode(head,third,40);
    printf("after insertion\n");
   linkedlisttrvarsal(head);
}