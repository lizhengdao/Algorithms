#include <iostream>
using namespace std;
int BitSwapReqd(int A, int B)
{
    int count = 0, x = A ^ B;
    for (; x != 1; x /= 2)
    {
        if (x % 2)
            count++;
    }
    count++;
    return count;
}
int main()
{
    int a = 5, b = 120;
    cout << BitSwapReqd(a, b) << " bit swaps are needed to convert " << a << " to " << b << "\n";
    return 0;
}