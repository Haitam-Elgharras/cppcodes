#include <iostream>
#include <chrono>

// nomé "tri bulle" car les plus grandes valeurs "flottent" vers le haut
//  de la liste comme des bulles à la surface d'un liquide.
void bubble_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90, 64, 34, 25, 12, 22, 11, 90, 64, 34, 25, 12, 22, 11, 90, 64, 34, 25, 12, 22, 11, 90, 64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << n;
  std::cout << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  bubble_sort(arr, n);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "Sorted array: \n";

  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Time spent with the O(n^2): " << duration.count() << " microseconds" << std::endl;

  return 0;
}
