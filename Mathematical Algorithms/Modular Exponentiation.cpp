#include <iostream>
using namespace std;
//Complextiy: O(log N)
long long mod_pow(long long num, long long pow, long long mod)
{
    long long ret = 1;
    while (pow)
    {
        if (pow & 1)
        {
            ret = (ret * num) % mod;
        }
        pow >>= 1;
        num = (num * num) % mod;
    }
    return ret;
}

long long mod_inv(long long num, long long mod)
{
    return mod_pow(num, mod - 2, mod);
}

int main()
{
    cout << mod_pow(15, 2, 8) << "\n";
    cout << mod_inv(1423, 13) << "\n";
    return 0;
}