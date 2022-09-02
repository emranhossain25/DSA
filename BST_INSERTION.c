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
    printf("enter left child of %d \n",data);
    n->left=createnode();
    printf("enter right of %d \n",data);
    n->right=createnode();
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
int isBST(struct node * root)
{
    struct node * prev = NULL;
    if (root!=NULL)
    {
        return 0;
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && root->data<= prev->data)
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
 struct node * SEARCHNODE(struct node * root,int key)
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
      return SEARCHNODE(root->left,key);  
     }
     else
     {
         return SEARCHNODE(root->right,key);
     }
     
 }
void insert(struct node * root,int key)
{
    struct node * prev=NULL;
    while (root!=NULL)
    {
        prev=root;
        if (key==root->data)
        {
            printf("cannot insert %d already in BST\n",key);
            return;
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
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=key;
    if (key<prev->data)
    {
        prev->left=new;
    }
    else
    {
        prev->right=new;
    }
}

int main()
{
    int key;
    struct node * root;
    root=NULL;
    root=createnode();
    inORDER(root);
    printf("\n");
    printf("enter the element which you want to insert\n");
    scanf("%d",&key);
    insert(root,key);
    inORDER(root);
    //printf("%d",root->right->right->data);
    return 0;
}