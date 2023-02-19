#include <iostream>
#include <algorithm>

void quicksort(int *number, int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int count;
    std::cout << "How many elements are you going to enter?: ";
    std::cin >> count;
    std::cout << "Enter " << count << " elements: ";
    int *number = new int[count];
    for (int i = 0; i < count; i++)
        std::cin >> number[i];
    quicksort(number, 0, count - 1);
    std::cout << "Order of Sorted elements: ";
    for (int i = 0; i < count; i++)
        std::cout << " " << number[i];
    delete[] number;
    return 0;
}
