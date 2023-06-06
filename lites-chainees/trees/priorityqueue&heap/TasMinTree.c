
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(TreeNode *node)
{
    if (node->left != NULL && node->left->val < node->val)
    {
        swap(&node->left->val, &node->val);
        heapifyUp(node->left);
    }
    if (node->right != NULL && node->right->val < node->val)
    {
        swap(&node->right->val, &node->val);
        heapifyUp(node->right);
    }
}

void insert(TreeNode **root, int val)
{
    if (*root == NULL)
    {
        *root = createNode(val);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            (*root)->left = createNode(val);
            heapifyUp(*root);
        }
        else if ((*root)->right == NULL)
        {
            (*root)->right = createNode(val);
            heapifyUp(*root);
        }
        else if ((*root)->left->val > (*root)->right->val)
        {
            insert(&(*root)->right, val);
        }
        else
        {
            insert(&(*root)->left, val);
        }
    }
}

void display(TreeNode *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->val);
        display(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;
    insert(&root, 4);
    insert(&root, 3);
    insert(&root, 12);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 1);
    display(root);
}