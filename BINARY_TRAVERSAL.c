#include<stdio.h>
#include<malloc.h>

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
    struct node *p=createnode(4);
    struct node *p1=createnode(1);
    struct node *p2=createnode(6);
    struct node *p3=createnode(8);
    struct node *p4=createnode(3);
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("PREORDER TRAVERSAL\n");
    preORDER(p);
    printf("POSTORDER TRAVERSAL\n");
    postORDER(p);
    printf("INORDER TRAVERSAL\n");
    inORDER(p);
    return 0;
}
