#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

int rechercherDichotomie(int *T, int x, int min, int max)
{
    if (min > max)
        return -1;

    int mid = (min + max) / 2;

    if (T[mid] == x)
        return mid;
    else if (x < T[mid])
        return rechercherDichotomie(T, x, min, mid - 1);
    else
        return rechercherDichotomie(T, x, mid + 1, max);
}

int main()
{

    int n = 1;
    int *T = new int[1];

    T[0] = 0;
    int x = 5;
    int min = 0;
    int max = n - 1;
    int res = rechercherDichotomie(T, x, min, max);
    cout << "Resultat : " << res << endl;

    // int n = 1000000;
    // int *T = new int[n];
    // for (int i = 0; i < n; i++)
    //     T[i] = i;
    // int x = 0;
    // int min = 0;
    // int max = n - 1;
    // auto start = chrono::high_resolution_clock::now();
    // int res = rechercherDichotomie(T, x, min, max);
    // auto end = chrono::high_resolution_clock::now();
    // cout << "Resultat : " << res << endl;

    // cout << "Temps d'execution : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    return 0;
}