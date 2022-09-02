#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * create()
{
    int data;
    struct node * n;
    n=(struct node *)malloc(sizeof(struct node));
    printf("enter data(-1 for no node)\n");
    scanf("%d",&data);
    if (data==-1)
    {
        return NULL;
    }
    n->data=data;
    printf("enter left child of %d\n",data);
    n->left=create();
    printf("enter right child of %d\n",data);
    n->right=create();
    return n;
}

void preORDER(struct node * root)
{
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preORDER(root->left);
        preORDER(root->right);
    }
    
}

void postORDER(struct node * root)
{
    if (root!=NULL)
    {
        postORDER(root->left);
        postORDER(root->right);
        printf("%d ",root->data);
    }
    
}

void inORDER(struct node * root)
{
    if (root!=NULL)
    {
        inORDER(root->left);
        printf("%d ",root->data);
        inORDER(root->right);
    }
    
}

struct node * inOrderPREDESSOR(struct node * root)
{
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node * deleteNODE(struct node * root,int value)
{
    struct node * ipre;
    if (root==NULL)
    {
       return NULL;
    }
    if (root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if (value<root->data)
    {
        root->left=deleteNODE(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=deleteNODE(root->right,value);
    }
    else
    {
        ipre=inOrderPREDESSOR(root);
        root->data=ipre->data;
        root->left=deleteNODE(root->left,ipre->data);
    }
    return root;
}

int main()
{
    int value;
    struct node * root;
    root=NULL;
    root=create();
    inORDER(root);
    printf("\n");
    printf("enter the data which you want to delete\n");
    scanf("%d",&value);
    deleteNODE(root,value);
    printf("\n");
    inORDER(root);
    return 0;
}