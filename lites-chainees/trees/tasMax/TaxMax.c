/*

****Dans ce programme de test(TasMax), j'ai répété exactement ce que j'ai fait lors de l'examen,
->le max et correctement returné.
-> il réussit à trier parfaitement un tableau d'entiers.
->Le programme respecte les propriétés d'un tas maximum, où la racine d'un sous-arbre est toujours supérieure ou égale à ses fils.


****Cependant, après les tests, j'ai remarqué un problème avec les fonctions d'insertion (insert) et de suppression (supprimer).
 Elles ne garantissent pas que les éléments restent toujours à leur position correcte dans le sous-arbre.
 Il est possible que leur position change en fonction de leur valeur, ce qui peut altérer l'ordre du tas.

aprés la révision de cours j'ai trouver la relation entre l'indice de l'élément et ses fils et père
tq le père est (i-1)/2 et les fils sont 2*i+1 et 2*i+2

et on utilisant cette relation j'ai corrigé les fonctions d'insertion et de suppression
et j'ai ajouter la version corrigé dans le fichier TaxMaxPreserve.c

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *tab;
    int maxSize;
    int size;
} TasMax;

TasMax *createTas(int capacity)
{

    TasMax *Tas = (TasMax *)malloc(sizeof(TasMax));
    Tas->tab = (int *)malloc(capacity * sizeof(int));
    Tas->maxSize = capacity;
    Tas->size = 0;
    return Tas;
}
int max(TasMax *Tas)
{
    return Tas->tab[0];
}
void insert(TasMax *Tas, int element)
{
    if (Tas->size == Tas->maxSize)
    {
        printf("Tas plein");
        return;
    }
    else if (Tas->size == 0)
    {
        Tas->tab[0] = element;
        Tas->size++;
        return;
    }
    else
    {
        // on cherche le permier element inférieur a elemnt et a a position on met le nouvel element et on decale les autres a droite
        int i = 0;
        while (i < Tas->size && Tas->tab[i] > element)
        {
            i++;
        }
        int j = 0;
        for (j = Tas->size - 1; j >= i; j--)
        {
            Tas->tab[j + 1] = Tas->tab[j];
        }
        Tas->tab[i] = element;
        Tas->size++;
    }
    return;
}
void supprimer(TasMax *Tas)
{
    if (Tas->size == 0)
    {
        printf("Tas vide");
        return;
    }
    else
    {
        int i = 0;
        for (i = 0; i < Tas->size - 1; i++)
        {
            Tas->tab[i] = Tas->tab[i + 1];
        }
        Tas->size--;
    }
    return;
}
void triParTas(int *tab, int n)
{
    TasMax *Tas = createTas(n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        insert(Tas, tab[i]);
    }
    // le max doit etre a la fin du tableau
    for (i = n - 1; i >= 0; i--)
    {
        tab[i] = max(Tas);
        supprimer(Tas);
    }
    return;
}
void display(TasMax *Tas)
{
    int i = 0;
    for (i = 0; i < Tas->size; i++)
    {
        printf("%d ", Tas->tab[i]);
    }
    printf("\n");
    return;
}

int main()
{
    TasMax *testTas = NULL;
    testTas = createTas(10);
    insert(testTas, 20);
    insert(testTas, 15);
    insert(testTas, 8);
    insert(testTas, 10);
    insert(testTas, 7);
    insert(testTas, 4);
    insert(testTas, 30);
    insert(testTas, 40);
    insert(testTas, 45);
    insert(testTas, 19);
    display(testTas);
    int tmp = testTas->size;
    for (int i = 0; i < tmp; i++)
    {
        supprimer(testTas);
        display(testTas);
    }
    return 0;
}
