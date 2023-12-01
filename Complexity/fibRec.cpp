#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int res = fib(20);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Result: " << res << endl;
    cout << " Duration: " << duration.count();
}