#include <iostream>
using namespace std;
//Extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1, gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
    long long x, y, a = 35, b = 15, g = gcdExtended(a, b, &x, &y);
    cout << "gcd(" << a << ", " << b << ") = " << g << ", x = " << x << ", y = " << y;
    return 0;
}