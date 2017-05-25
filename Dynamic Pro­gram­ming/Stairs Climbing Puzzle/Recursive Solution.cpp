#include <iostream>
using namespace std;
int possibleWays(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return 1 + possibleWays(n - 1) + possibleWays(n - 2) + possibleWays(n - 3);
}
int main()
{
    cout << possibleWays(4) << " ways are possible.\n";
    cout << possibleWays(15) << " ways are possible.";
    return 0;
}