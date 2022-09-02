#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node * left;
    struct node * right;
    int height;
};

 int getheight(struct node * n)
 {
     if (n==NULL)
     {
         return 0;
         return n->height;
     }
     
 }
struct node *createNode(int key){
    struct node* new= (struct node *) malloc(sizeof(struct node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int getBALENCEfactor(struct node * n)
{
    if (n==NULL)
    {
        return 0;
    }
    return getheight(n->left)-getheight(n->right);
}
struct node * leftROTATE(struct node * x)
{
    struct node * y = x->right;
    struct node  * t2 = y->left;

    y->left=x;
    x->right=t2;

    x->height=max(getheight(x->right),getheight(x->left)) + 1;
    y->height=max(getheight(y->right),getheight(y->left)) + 1;
    return y;
}

struct node * rightROTATE(struct node * y)
{
    struct node * x = y->left;
    struct node * t2 = x->right;

    x->right=y;
    y->left=t2;

    x->height=max(getheight(x->right),getheight(x->left)) + 1;
    y->height=max(getheight(y->right),getheight(y->left)) + 1;
    return x;
}
 void preORDER(struct node * root)
{
    if (root!=NULL)
    {
        printf("%d ",root->key);
        preORDER(root->left);
        preORDER(root->right);
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