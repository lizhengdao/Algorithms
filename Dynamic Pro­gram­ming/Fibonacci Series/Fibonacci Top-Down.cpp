#include <iostream>
using namespace std;
long long fib[10001];
long long fibTopDown(int n)
{
    if (n == 0)
        return 0;
    if (fib[n])
        return fib[n];
    else
    {
        fib[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
        return fib[n];
    }
}
int main()
{
    for (int i = 0; i < 10001; i++)
        fib[i] = 0;
    fib[1] = 1;
    cout << fibTopDown(0) << "\n";
    cout << fibTopDown(1) << "\n";
    cout << fibTopDown(6) << "\n";
    cout << fibTopDown(10) << "\n";
    return 0;
}