#include<stdio.h>
#include<stdlib.h>

//structer of the threaded BST node
struct node
{
    int data;
    struct node * left;
    struct node * right;
    int Lbit;
    int Rbit;
};
struct node * head;
struct node * parent;

//inserting any node
void insert(struct node * root, struct node * temp)
{
    //for root left child
    if (root->data > temp->data)
    {   
        if(root->left == head)
        {
            temp->left = root->left;
            temp->right = root;
            root->left = temp;
            root->Lbit = 1;
        }
        else if(root->left == parent)
        {
            temp->left = root->left;
            temp->right = root;
            root->left=temp;
            root->Lbit=1;
        }
        else
        {
            parent =root;
            insert(root->left,temp);
        }
        
    }
    //for root right child
    if(root->data < temp->data)
    {
        if(root->right == head)
        {
            temp->right = root->right;
            temp->left = root;
            root->right = temp;
            root->Rbit = 1;
        }
        else if(root->right == parent)
        {
            temp->right = root->right;
            temp->left = root;
            root->right=temp;
            root->Rbit=1;
        }
        else
        {
            parent = root;
            insert(root->right ,temp);
        }
        
    }
    
}

//creating the threaded binary tree
void creatnode(struct node * root)
{
    int val,ch;
    do
    {
        //creating the node 
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value:\n");
        scanf("%d",&val);
        temp->data = val;
        temp->Lbit =temp->Rbit = 0;
        temp->left=temp->right = NULL;

        if (root == NULL)
        {
            root=temp;
            //creating the dummy node
            head = (struct node *)malloc(sizeof(struct node));
            head->data = 999;
            head->Lbit = head->Rbit =1;
            head->right = head;
            head->left = root;
            root->left = head;
            root->right = head;

        }
        else
        {
            insert(root,temp);
            printf("Do you want to insert more >> press 1 for yes 0 for no\n");
            scanf("%d",&ch);
        }

    } while (ch);
    
}

//preorder traversal of the threaded bst
void preorderTraverse(struct node * head)
{
    struct node * t = head->left;
    do
    {
        while (t->Lbit != 0)
        {
            printf("%d  ",t->data);
            t=t->left;    
        }
        printf("%d  ",t->data);

        while (t->Rbit == 0)
        {
            t=t->right;
            if(t==head){
                return;
            }
        }
        t=t->right;
    } while (t != head);
    
}

int main(){
    struct node * root = NULL;
    creatnode(root);

    preorderTraverse(head);
    printf("\n");
    return 0;
}