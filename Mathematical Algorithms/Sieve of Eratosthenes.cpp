#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;
/*  Prime generation using Sieve of Eratosthenes
    Complexity: O(N log log N)
*/
vector<long long> sieve(long long B)
{
    vector<long long> primes;
    bool mark[MAX_N];
    if (B > 1)
        primes.push_back(2);
    for (long long i = 3; i <= B; i += 2)
    {
        if (!mark[i])
        {
            mark[i] = true;
            primes.push_back(i);
            if (i <= sqrt(B) + 1)
            {
                for (long long j = i * i; j <= B; j += i)
                    mark[j] = true;
            }
        }
    }
    return primes;
}

int main()
{
    vector<long long> primes = sieve(30);
    for (long long i = 0; i < primes.size(); i++)
        cout << primes[i] << "\n";
    return 0;
}