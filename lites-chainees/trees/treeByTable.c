#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **table; // 0 pour val , 1 pour nombre des noued
    int nbNoued;
} treeByTable;

void getTreeInput(treeByTable *tree)
{
    int i = 0, j = 0;
    int nb = 0;
    int val = 0;
    printf("donner moi le nombre de noued dans cette arbre\n");
    scanf("%d", &tree->nbNoued);
    tree->table = (int **)malloc(tree->nbNoued * sizeof(int *));
    for (i = 0; i < tree->nbNoued; i++)
    {
        printf("donner moi le nombre des enfents de la noued %d est sa valeur \n", i + 1);
        scanf("%d%d", &nb, &val);
        tree->table[i] = (int *)malloc((nb + 2) * sizeof(int));
        tree->table[i][0] = val;
        tree->table[i][1] = nb;
        printf("donner les indces des enfantes de  la noued %d\n", i + 1);
        for (j = 2; j < nb + 2; j++)
        {
            scanf("%d", &val);
            tree->table[i][j] = val;
        }
    }
}

void printTreeValues(treeByTable tree)
{
    int i = 0;
    printf("les valuers dans l'arbre sont : ");
    for (i = 0; i < tree.nbNoued; i++)
    {
        printf("%d ", tree.table[i][0]);
    }
}

int main()
{
    treeByTable myTree;
    getTreeInput(&myTree);
    printTreeValues(myTree);
    return 0;
}
