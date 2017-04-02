#include <iostream>
using namespace std;
int next_power_of_2(int x)
{
    x -= 1;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x += 1;
    return x;
}
int main()
{
    int a = 5;
    cout << "Next power of 2 after " << a << " is " << next_power_of_2(a);
    return 0;
}