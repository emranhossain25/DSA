#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void linklisttraversal(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("element :%d\n",ptr->data);
        ptr=ptr->next;
    }
    
} 

struct node * deleteatfirst(struct node * head)
{
    struct node * ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}

struct node * deleteatindex(struct node * head, int index)
{
    struct node * p = head;
    struct node * q = head->next;
    for (int i = 0; i <index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node * deleteatend(struct node * head)
{
    struct node * p = head;
    struct node * q =head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    return head;
}

int main()
{
   struct node *head;
   struct node *second;
   struct node *third;
   struct node *forth;
   struct node *fifth;

   head=(struct node*)malloc(sizeof(struct node)); 
   second=(struct node*)malloc(sizeof(struct node)); 
   third=(struct node*)malloc(sizeof(struct node)); 
   forth=(struct node*)malloc(sizeof(struct node)); 
   fifth=(struct node*)malloc(sizeof(struct node)); 

    head->data=5;
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=15;
    third->next=forth;
    
    forth->data=20;
    forth->next=fifth;
    
    fifth->data=25;
    fifth->next=NULL;
    printf("before deletion\n");
    linklisttraversal(head);
 //  head=deleteatfirst(head);
 //head=deleteatindex(head,2);
 head=deleteatend(head);
 printf("after deletion\n");
    linklisttraversal(head);
     
    return 0;
}