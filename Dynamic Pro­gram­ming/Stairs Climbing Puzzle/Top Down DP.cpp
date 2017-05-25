#include <iostream>
using namespace std;
int possibleWaysDP(int n, int *dyn)
{
    if (n < 1)
        return 0;
    if (dyn[n] <= 0)
        dyn[n] = 1 + possibleWaysDP(n - 1, dyn) + possibleWaysDP(n - 2, dyn) + possibleWaysDP(n - 3, dyn);
    return dyn[n];
}
int main()
{
    int dyn[16] = {0};
    cout << possibleWaysDP(4, dyn) << " ways are possible.\n";
    cout << possibleWaysDP(15, dyn) << " ways are possible.";
    return 0;
}