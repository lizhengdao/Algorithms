#include <iostream>
#define MOD 1000000007
using namespace std;
long long fast_power(long long base, long long power)
{   
    long long result = 1;
    while(power > 0)
    {   
        if(power & 1)
            result = (result*base) % MOD;
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}
int main()
{   
    cout << fast_power(2, 1) << endl; // Output: 2
    cout << fast_power(2, 2) << endl; // Output: 4
    cout << fast_power(2, 4) << endl; // Output: 16
    cout << fast_power(3, 4) << endl; // Output: 81
    cout << fast_power(2, 100) << endl; // Output: 976371285
    return 0;
}