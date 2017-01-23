#include <iostream>
using namespace std;
/*  Euler’s Totient function Φ(n) is count of numbers in {1, 2, …, n} that are relatively prime to n,
    i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
*/
long long phi(long long n)
{
    long long result = n;
    // Consider all prime factors of n and subtract their multiples from result
    for (long long p = 2; p * p <= n; ++p)
    {
        if (n % p == 0) // Check if p is a prime factor.
        {
            while (n % p == 0) // If yes, then update n and result
                n /= p;
            result -= result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n) (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    for (int i = 1; i <= 10; i++)
        cout << "phi(" << i << ")=" << phi(i) << "\n";
    return 0;
}