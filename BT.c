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
struct sNode
{
struct tNode *t;
struct sNode *next;
};

struct sNode * push(struct sNode * top, struct tNode * t)
{
  
} 

int main()
{
    struct node * root;
    root=NULL;
    root=createnode();

    return 0;
}