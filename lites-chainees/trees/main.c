#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    tree *myTree = creatTree();
    myTree = addTree(5, NULL, NULL);
    myTree->leftTree = addTree(3, NULL, NULL);
    myTree->rightTree = addTree(7, NULL, NULL);
    myTree->leftTree->leftTree = addTree(1, NULL, NULL);
    myTree->leftTree->rightTree = addTree(6, NULL, NULL);
    myTree->rightTree->leftTree = addTree(9, NULL, NULL);
    myTree->rightTree->rightTree = addTree(12, NULL, NULL);
    tree *test = creatTree();
    test = addTree(5, myTree->leftTree, myTree->rightTree);
    test->leftTree->data = 99;
    printf("this is test :\n");
    displayTree(test);
    printf("this is my tree :\n");
    displayTree(myTree);
    test->leftTree->data = 5;
    int value = 6;
    if (search(test, value))
    {
        printf("%d is in the tree.\n", value);
    }
    else
    {
        printf("%d is not in the tree.\n", value);
    }

    return 0;
}
