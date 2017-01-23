#include <iostream>
using namespace std;
/*  Euclid's Algorithm for GCD or HCF
    Complexity: O(log^2 N)
*/
long long gcd(long long a, long long b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
//LCM using GCD
long long lcm(long long a, long long b)
{
    return a * (b / gcd(a, b));
}

int main()
{
    cout << gcd(45, 60) << "\n";
    cout << lcm(45, 60) << "\n";
    return 0;
}