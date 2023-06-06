#include <iostream>
/*we suppose that the 1st element is in his place ? we save the place of the first element after it in a key
 and we start the sorting from the place j+1, we compare the element in the place j+1with the element
 sorted after it (j>=0 && j<j+1) if we find that this j bigger than key we change the place of the j to the place of the key
 ....
 */
void insertion_sort(int arr[], int n) // la complixité est O(n^2)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    // j c'est la place des elements triées
    while (j >= 0 && key < arr[j])
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  /*les étapes du tri par insertion pour un tableau de taille 4 [2,3,4,1] :

Initialement, l'élément 2 est considéré comme le premier élément trié et le tableau restant contient les éléments [3,4,1].

Ensuite, l'élément 3 est comparé avec l'élément trié 2. Comme 3 est supérieur à 2, il est simplement inséré à la suite de 2. Le tableau trié est maintenant [2,3] et le tableau non trié est [4,1].

L'élément 4 est comparé avec les éléments triés [2,3]. Comme 4 est supérieur à 3 et supérieur à 2, il est inséré à la suite de 3. Le tableau trié est maintenant [2,3,4] et le tableau non trié est [1].

L'élément 1 est comparé avec les éléments triés [2,3,4]. Comme 1 est inférieur à 4 donc 4 va decaleé vers le droit
aussi 3 et 2 puis 1 va étre inserée a j=0

 après  ces 4 étapes, le tableau est trié et est maintenant [1,2,3,4].*/
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertion_sort(arr, n);

  std::cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
