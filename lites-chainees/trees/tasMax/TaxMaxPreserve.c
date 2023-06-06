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
    TasMax *Tas = malloc(sizeof(TasMax));
    Tas->tab = malloc(capacity * sizeof(int));
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
        printf("invalid operation");
        return;
    }
    else
    {
        int i = Tas->size;
        while (i > 0 && element > Tas->tab[(i - 1) / 2])
        {
            Tas->tab[i] = Tas->tab[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        Tas->tab[i] = element;
        Tas->size++;
    }
}
void supprime(TasMax *Tas)
{
    if (Tas->size == 0)
    {
        printf("invalid operation");
        return;
    }
    else
    {
        int lastElement = Tas->tab[Tas->size - 1];
        Tas->size--;
        int i = 0;
        while (2 * i + 1 < Tas->size)
        {
            int fils = 2 * i + 1;
            if (fils + 1 < Tas->size && Tas->tab[fils + 1] > Tas->tab[fils])
            {
                fils++;
            }
            if (lastElement >= Tas->tab[fils])
            {
                break;
            }
            Tas->tab[i] = Tas->tab[fils];
            i = fils;
        }
        Tas->tab[i] = lastElement;
    }
}

void trier(int *tab, int capacity)
{
    TasMax *Tas = createTas(capacity);
    for (int i = 0; i < capacity; i++)
    {
        insert(Tas, tab[i]);
    }
    for (int i = capacity - 1; i >= 0; i--)
    {
        tab[i] = max(Tas);
        supprime(Tas);
    }
    free(Tas->tab);
    free(Tas);
}
void display(TasMax *Tas)
{
    printf("le Tas max est : ");
    for (int i = 0; i < Tas->size; i++)
    {
        printf("%d ", Tas->tab[i]);
    }
    printf("\n");
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
        supprime(testTas);
        display(testTas);
    }
    return 0;
}
