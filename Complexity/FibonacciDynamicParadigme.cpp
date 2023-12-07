#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
int N = 50;
unsigned long long *T = new unsigned long long[N];
int lastCalculatedIndex = 1;

unsigned long long fib(unsigned long long n)
{
    if (n >= N)
    {
        N += n;
        T = (unsigned long long *)realloc(T, (N) * sizeof(unsigned long long));

        for (int i = lastCalculatedIndex + 1; i < N; i++)
            T[i] = 0;
    }
    else if (T[n] != 0 && n != 0)
        return T[n];

    T[0] = 0;
    T[1] = 1;

    for (int i = lastCalculatedIndex + 1; i <= n; i++)
        T[i] = T[i - 1] + T[i - 2];

    lastCalculatedIndex = n;

    return T[n];
}

int main()
{
    while (true)
    {
        int n;
        cout << "Enter n: ";
        cin >> n;

        if (n == -1)
            break;

        auto start = chrono::high_resolution_clock::now();
        unsigned long long res = fib(n);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Result: " << res << endl;
        cout << " Duration: " << duration.count() << " microseconds" << endl;
    }

    delete[] T; // Don't forget to free the allocated memory before exiting

    return 0;
}