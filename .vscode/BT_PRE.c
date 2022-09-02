#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct stack
{
    struct node * data;
    struct stack * next;
};

void push(struct stack  **top,struct node * data)
{
    struct stack * new;
    new=(struct stack *)malloc(sizeof(struct stack));
    if (new==NULL)
    {
       printf("stack overflow\n");
    }
    new->data=data;
    new->next=(*top);
    (*top)=new;
}

struct stack * pop(struct stack ** top)
{
    struct node * p;
    struct stack * tp;
    if (top==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        tp=(*top);
        p=tp->data;
        (*top)=tp->next;
        free(tp);
        return p;
    }
}
struct node * createnode()
 {
     int data;
     struct node * n;
     n=(struct node * )malloc(sizeof(struct node));
     printf("enter data(-1 for no node)\n");
     scanf("%d",&data);
     if (data==-1)
     {
        return NULL;
     }
     n->data=data;
     printf("enter left child of %d\n",data);
     n->left=createnode();
     printf("enter right child of %d\n",data);
     n->right=createnode();
     return n;
 }
 void preORDER(struct node * root)
 {
     struct node * curr = root;
     struct stack * s = NULL;
     while (curr!=NULL)
     {
         printf("%d ",curr->data);
         if (curr->right!=NULL)
         {
             push(&s,curr->right);
         }
         if (curr->left!=NULL)
         {
             curr=curr->left;
         }
         else
         {
             curr = pop(&s);
         }
         
     } 
 }
 int main()
 {
     struct node * root;
     root=NULL;
     root=createnode();
     preORDER(root);
     return 0;
 }