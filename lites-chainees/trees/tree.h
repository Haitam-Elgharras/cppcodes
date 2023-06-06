#include <stdio.h>
#include <stdlib.h>

/*
add dégénéré : we dont have any tree has two childs
*/
typedef struct tree
{
    int data;
    struct tree *rightTree;
    struct tree *leftTree;
} tree;

tree *creatTree();
tree *addTree(int, tree *, tree *);
// infixed display (left child then right child)
void displayTree(tree *);
int getNbN(tree *);      // number of nodes in the tree
int getNbF(tree *);      // number of nodes with no child
int search(tree *, int); // searching a value in the tree
tree *deepCopy(tree *);  // To avoid the problem of shallow copy
                         /*if we pass the left and right pointers of an existing tree to the new tree, the new tree will point
                         to the same memory locations that the original tree is pointing to. This is called a shallow copy,
                          where we are copying the memory address of the pointer and not the data that the pointer is pointing to.*/