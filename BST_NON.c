#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};
//stack using Linked List
struct node2
{
    struct node * adress;
    struct node2* next;
};

void push(struct node2* head ,struct node * ptr)
{
    struct node2 * newnode = (struct node2 *)malloc(sizeof(struct node2));
    newnode->adress = ptr;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void pop(struct node2* head)
{
    if (head == NULL)
    {
        return;
    }
    struct node2 * p =head->next;
    struct node2 * q =head;
    while (p->next != NULL)
    {
        q=q->next;
        p=p->next;

    }
    q->next = p->next;
}

struct node * stackTop(struct node2 * head)
{
    return head->adress;
}

struct node * creatTree()
{
    int x;
    struct node * root = (struct node *)malloc(sizeof(struct node ));
    printf("Enter data (Enter -1 for no node) : \n");
    scanf("%d",&x);
    if (x==-1)
    {
        return NULL;
    }
    root->data = x;
    printf("Enter the left node of %d\n",x);
    root->left = creatTree();
    printf("Enter the right node of %d\n",x);
    root->right= creatTree();
    
    return root;
}

void preorderTraversal(struct node * root)
{
    struct node * ptr;
    if (root==NULL)
    {
        printf("Tree is empty");
        return;
    }
    else
    {
        ptr = root;
    }
    //initialized an empty stack
    struct node2 * top = NULL;
    while (ptr !=NULL)
    {
        printf("%d ",ptr->data);

        if (ptr->right != NULL)
        {
            push(top, ptr->right);
        }
        if (ptr->left != NULL)
        {
            ptr=ptr->left;
        }
        else
        {
            ptr=stackTop(top);
        }
        
    }
}

int main(){
    struct node * root = NULL;
    root=creatTree();

    printf("Postorder traversal is:\n");
    preorderTraversal(root);
    printf("\n");

    return 0;
}