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
    }
    return n->height;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int getbalencefactor(struct node * n)
{
    if (n==NULL)
    {
        return 0;
    }
    return getheight(n->left)-getheight(n->right);
}

struct node * rightrotate(struct node * y)
{
    struct node * x = y->left;
    struct node * t2 = x->right;

    x->right=y;
    y->left=t2;

    x->height=1 + max(getheight(x->right),getheight(x->left));
    y->height=1 + max(getheight(y->right),getheight(x->left));
    
    return x;
}

struct node * leftrotate(struct node * x)
{
    struct node * y = x->right;
    struct node * t2 = y->left;

    y->left=x;
    x->right=t2;

    x->height=1 + max(getheight(x->right),getheight(x->left));
    y->height=1 + max(getheight(y->right),getheight(y->left));
    return y;
}

struct node *createNode(int key){
    struct node* new= (struct node *) malloc(sizeof(struct node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}


struct node * insert(struct node* n, int key){
    if (n == NULL){
        return  createNode(key);
    }
    if (key < n->key){
        n->left  = insert(n->left, key);
    }
    else if (key > n->key){
        n->right = insert(n->right, key);
    }
    n->height = 1 + max(getheight(n->left), getheight(n->right));
    int bf = getbalencefactor(n);
 
        if(bf>1 && key < n->left->key)  //LEFT LEFT ROTATION
        {
            return rightrotate(n);
        }
        if(bf<-1 && key > n->right->key) //LEFT RIGHT ROTATION
        {
            return leftrotate(n);
        }
    if(bf>1 && key > n->left->key)  //left right rotaion 
     {
            n->left = leftrotate(n->left);
            return rightrotate(n);
        }
    if(bf<-1 && key < n->right->key) //right left rotation 
    {
         n->right = rightrotate(n->right);
            return leftrotate(n);
        }
    return n;
}
void preORDER(struct node* root)
{
    if (root!=NULL)
    {
        printf("%d ",root->key);
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
        printf("%d ",root->key);
    }
    
}

 void inORder(struct node * root)
 {
     if (root!=NULL)
     {
         inORder(root->left);
         printf("%d ",root->key);
         inORder(root->right);
     }
 }

 int main()
 {
     int choice,key;
     struct node * root;
     root=NULL;
     while (choice)
     {
         printf("enter the key which you want to insert\n");
         scanf("%d",&key);
         root=insert(root,key);
         printf("DO YOU WANT TO INSERT(0,1)\n");
         scanf("%d",&choice);
     }
     
     /*root=insert(root,4);
     root=insert(root,2);
     root=insert(root,10);
     root=insert(root,5);
     root=insert(root,7);*/
     inORder(root);
     return 0;
 }
 