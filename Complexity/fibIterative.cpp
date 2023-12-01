#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
int N = 200;
long long *T = new long long[N];

long long fib(long long n)
{
    if (n >= N)
    {
        N = n + 1;
        T = (long long *)realloc(T, (N) * sizeof(long long));
    }

    if (T[n] != 0 && n != 0)
        return T[n];

    T[0] = 0;
    T[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        T[i] = T[i - 1] + T[i - 2];
    }

    return T[n];
}

int main()
{
    //

    while (true)
    {
        int n;
        cout << "Enter n: ";
        cin >> n;

        if (n == -1)
            break;

        auto start = chrono::high_resolution_clock::now();
        long long res = fib(n);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Result: " << res << endl;
        cout << " Duration: " << duration.count() << endl;
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // cout << "Result: " << res << endl;
    // cout << " Duration: " << duration.count();
}