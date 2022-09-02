#include <stdio.h>
#include <stdlib.h>
 
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Stack type
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};
 
// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}
//creat tree
struct Node *createtree()
{
    int data;
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data(-1 for no node)\n");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    n->data = data;
    printf("enter left child of %d\n", data);
    n->left = createtree();
    printf("enter right child of %d\n", data);
    n->right = createtree();
    return n;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{ return stack->top == -1; }
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
 
// An iterative function to do postorder traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;
     
    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                push(stack, root->right);
            push(stack, root);
 
            // Set root as root's left child
            root = root->left;
        }
 
        // Pop an item from stack and set it as root    
        root = pop(stack);
 
        if (root->right && peek(stack) == root->right)
        {
            pop(stack); // remove right child from stack
            push(stack, root); // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else // Else print root's data and set root as NULL
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    
    root = createnode();
    printf("Post order traversal of binary tree is :\n");
    
    postOrderIterative(root);
 
    return 0;
}