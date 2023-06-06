#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    int x;
    int y;
} Point;

Point **f(int n)
{
    Point **A = (Point **)malloc(n * sizeof(Point *));
    int i;
    for (i = 0; i < n; i++)
        A[i] = (Point *)malloc(n * sizeof(Point));

    return A;
}

void h(Point *T[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", T[i]->x, T[i]->y);
    }
}

void g(Point *T[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        T[i]->x = i;
        T[i]->y = i;
    }
}

int main()
{
    Point **B;
    B = f(3);
    g(B, 3);
    h(B, 3);
    return 0;
}
