#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree *creatTree()
{
    tree *stTree;
    stTree = (tree *)calloc(1, sizeof(tree));
    stTree->leftTree = NULL;
    stTree->rightTree = NULL;
    stTree->data = -1;
    return stTree;
}
// we add the right and the left trees to our tree , then if we want to do the same with the right part
//  we will write mainTree->right=addTree(int n, leftT, rightT)
tree *addTree(int n, tree *leftT, tree *rightT)
{
    tree *stTree;
    stTree = (tree *)calloc(1, sizeof(tree));
    stTree->data = n;
    stTree->leftTree = deepCopy(leftT);
    stTree->rightTree = deepCopy(rightT);
    return stTree;
}
// infixed display : we start from top-left then we will print the left the father the right
// if we want the préfixed just write the value before any display(father left right)
void displayTree(tree *theTree) // infixedDisplay()
{
    if (theTree != NULL)
    {

        displayTree(theTree->leftTree);
        if (theTree->data != -1)
        {
            printf(" the value of the racine is : %d \n", theTree->data);
        }
        displayTree(theTree->rightTree);
    }
    return;
}
int getNbN(tree *theTree)
{
    if (theTree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getNbN(theTree->leftTree) + getNbN(theTree->rightTree);
    }
}

int getNbF(tree *theTree)
{
    if (theTree != NULL)
    {
        if (theTree->leftTree == NULL && theTree->rightTree == NULL)
        {
            return 1;
        }
        else
        {
            return getNbF(theTree->leftTree) + getNbF(theTree->rightTree);
        }
    }
    else
    {
        return 0;
    }
}
int search(tree *theTree, int value)
{
    if (theTree == NULL)
    {
        return 0;
    }
    else if (theTree->data == value)
    {
        return 1;
    }
    else
    {
        return search(theTree->leftTree, value) || search(theTree->rightTree, value);
    }
}

tree *deepCopy(tree *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    // create a new node for the current node in the original tree
    tree *copy = (tree *)malloc(sizeof(tree));
    copy->data = original->data;

    // recursively copy the left and right subtrees
    copy->leftTree = deepCopy(original->leftTree);
    copy->rightTree = deepCopy(original->rightTree);

    return copy;
}
