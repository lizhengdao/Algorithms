#include <iostream>
using namespace std;
long long fibMemo(int n)
{
    long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}
int main()
{
    cout << fibMemo(0) << "\n";
    cout << fibMemo(1) << "\n";
    cout << fibMemo(6) << "\n";
    cout << fibMemo(10) << "\n";
    return 0;
}