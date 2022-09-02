#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main()
{
    struct node *p=createnode(2);
    struct node *p1=createnode(4);
    struct node *p2=createnode(5);
    struct node *p3=createnode(8);
    struct node *p4=createnode(7);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
}