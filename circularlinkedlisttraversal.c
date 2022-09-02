#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("circular linkedlist element:%d\n",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * forth;
    struct node * fifth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    forth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=14;
    second->next=third;

    third->data=21;
    third->next=forth;

    forth->data=28;
    forth->next=fifth;

    fifth->data=35;
    fifth->next=head;
   traversal(head);

   return 0;
}