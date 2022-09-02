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
void preORDER(struct node* root)
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

int main()
{
    struct node * root;
    struct node * n;
    int key;
    root=NULL;
    root=createnode();
   // isBST(root);
   preORDER(root);
   printf("\n");
   inORDER(root);
   printf("\n");
   postORDER(root);
    return 0;
}