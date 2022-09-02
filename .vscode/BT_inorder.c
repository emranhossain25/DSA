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
void  push(struct stack  ** top , struct node *data )
{
    struct stack * newnode = (struct stack *)malloc(sizeof(struct stack));
    if (newnode==NULL)
    {
        printf("stack overflow\n");
    }
    
    newnode->data=data;
    newnode->next=(*top);
    (*top)=newnode;
}

int isEmpty(struct stack * tp)
{
    if (tp==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
 struct node * pop(struct stack ** top)
{
     struct node * p;
     struct stack  * tp;
    if (isEmpty(tp))
    {
        printf("stack underflow");
    }
    else
    {
      tp = (*top);
    p = tp->data;
    (*top)= tp->next;
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

void inOrder(struct node * root)
{
    struct node * curr=root;
    struct stack * s = NULL;
    int flag=1;
    while (flag==1)
    {
        while (curr!=NULL)
        {
            push(&s,curr);
            curr=curr->left;
        }
        curr=pop(&s);
        flag=0;
        while (curr!=NULL && flag==0)
        {
            printf("%d ",curr->data);
            if (curr->right!=NULL)
            {
                curr=curr->right;
                flag=1;
            }
            else
            {
                curr=pop(&s);
            }
        }
        if (curr==NULL)
        {
            flag=0;
        }
        
    }
    
}

int main()
{
    struct node * root;
    root=NULL;
    root=createnode();
    inOrder(root);
}