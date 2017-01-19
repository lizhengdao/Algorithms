#include <iostream>
using namespace std;
bool isPowerOfTwo(long long x)
{
    return (x && !(x & (x - 1)));
}
int main()
{
    long long a = 31, b = 32, c = 1;
    cout << a << " is" << (isPowerOfTwo(a) ? " " : " not ") << "a power of 2\n";
    cout << b << " is" << (isPowerOfTwo(b) ? " " : " not ") << "a power of 2\n";
    cout << c << " is" << (isPowerOfTwo(c) ? " " : " not ") << "a power of 2\n";
}