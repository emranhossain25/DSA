#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode()
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
    n->left=createnode();
    printf("enter right child of %d\n",data);
    n->right=createnode();
    return n;
}
 int isBST(struct node * root)
 {
     static struct node * prev=NULL;
     if (root!=NULL)
     {
         return 0;
         if (!isBST(root->left))
         {
             return 0;
         }
         if (prev!=NULL && root->data<=prev->data)
         {
             return 0;
         }
         prev=root;
         return isBST(root->right);
     }
     else
     {
         return 1;
     }
     
 }
struct node * search(struct node * root,int key)
{
    if (root==NULL)
    {
        return NULL;
    }
    if (key==root->data)
    {
        return root;
    }
    else if (key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

struct node * searchiter(struct node * root,int key)
{
    while (root!=NULL)
    {
       if (key==root->data)
       {
           return root;
       }
        else if (key<root->data)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return NULL;
}
int main()
{
    struct node * root;
    struct node * n;
    int key;
    root=NULL;
    root=createnode();
    printf("entewr the element which you want to search\n");
    scanf("%d",&key);
    //n=search(root,key);
    n=searchiter(root,key);
    if (n!=NULL)
    {
       printf("ELEMENT FOUND:%d",n->data);
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }
    
    return 0;
}