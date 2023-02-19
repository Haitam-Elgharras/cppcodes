#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
void diviser(int *T, int n, int *t1, int *t2)
{
  int i, k;
  for (i = 0; i < n / 2; i++)
  {
    t1[i] = T[i];
  }
  k = 0;
  for (i = n / 2; i < n; i++)
  {
    t2[k] = T[i];
    k++;
  }
}

void fusion(int *t1, int n1, int *t2, int n2, int *T)
{
  int i, j, k;
  i = j = k = 0;
  // Fusionne les deux tableaux triés t1 et t2 pour les ranger dans T
  while (i < n1 && j < n2)
  {
    if (t1[i] < t2[j])
    {
      T[k] = t1[i];
      // s'il entre en T en passe a l'element suivant dans t1
      i++;
    }
    else
    {
      T[k] = t2[j];
      // s'il entre en T en passe a l'element suivant dans t2
      j++;
    }
    // en toutes cas en pass a la case suivant dans T
    k++;
  }
  // Ajouter les éléments restants de t1 s'ils existent
  while (i < n1)
  {
    T[k] = t1[i];
    i++;
    k++;
  }
  // Ajouter les éléments restants de t2 s'ils existent
  while (j < n2)
  {
    T[k] = t2[j];
    j++;
    k++;
  }
}
// pour comprendre essayer de simulé avec T={-3-1,2}
void trier(int *T, int n)
{
  int *t1, *t2;
  if (n > 1)
  {
    t1 = new int[n / 2];
    t2 = new int[n - n / 2];
    // on allons jusqu'a n=2 la f diviser travail une dernier fois
    // trier ne travaille pas on pass a fusionner le t1 et t2
    diviser(T, n, t1, t2);
    trier(t1, n / 2);
    trier(t2, n - n / 2);
    fusion(t1, n / 2, t2, n - n / 2, T);
    // Libération de la mémoire allouée pour le tableau t1
    delete[] t1;
    delete[] t2;
  }
}
// int T[] = {1,
//            20,
//            -10,
//            50,
//            60,
//            700,
//            53,
//            -900,
//            735,
//            -89, -822, 1000, 20000};
// trier(T, sizeof(T) / sizeof(T[0]));
// for (int k = 0; k < sizeof(T) / sizeof(T[0]); k++)
// {
//   cout << T[k] << "\t";
// }
// cout << endl;

int main()
{
  int i, j, n;
  int taille_max = 1000;
  ofstream fichier("data.txt");

  for (i = 10; i <= taille_max; i = i + 10)
  {
    n = i;
    // t=new int[n] est une instruction d'allocation dynamique de mémoire en C++
    int *T = new int[n];
    for (j = 0; j < n; j++)
    {
      T[j] = n - j;
    }

    auto start = chrono::high_resolution_clock::now();
    trier(T, n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // table affichage
    //  for (int k = 0; k < n; k++)
    //  {
    //    cout << T[k] << "\t";
    //  }
    // cout << endl;
    // cout << "table ";
    fichier << n << " " << duration.count() << endl;
    delete[] T;
  }
  // Appel de système pour générer la courbe
  int ret = system("gnuplot courbe_fusion.plt");
  if (ret == 0)
  {
    cout << "Courbe generee avec succes!" << endl;
  }
  else
  {
    cerr << "Erreur lors de la génération de la courbe" << endl;
  }

  fichier.close();

  return 0;
}

/*int main() {
int n, i;
 cout << "Entrer la taille du tableau à trier: ";
 cin >> n;
// t=new int[n] est une instruction d'allocation dynamique de mémoire en C++
int *T = new int[n];
 cout << "Entrer les éléments du tableau: " <<  endl;
for (i = 0; i < n; i++) {
//  cin >> T[i];
T[i]=i;
}

  auto start =  chrono::high_resolution_clock::now();
trier(T, n);
  auto end =  chrono::high_resolution_clock::now();
  auto duration =  chrono::duration_cast< chrono::microseconds>(end - start);

 cout << "Tableau trié: " <<  endl;
for (i = 0; i < n; i++) {
 cout << T[i] << " ";
}
delete [] T;
   cout << "Time spent with the O(nlog(n)): " << duration.count() << " microseconds" <<  endl;
return 0;
}*/