#include <iostream>
using namespace std;
//generic ternary search in array
template <typename T>
int ternary_search(const T arr[], const int size, const T e)
{
    int lo = 0, hi = size - 1, p1, p2;
    while (lo <= hi)
    {
        p1 = lo + (hi - lo) / 3;
        p2 = lo + (2 * (hi - lo) / 3);
        if (e == arr[p1])
            return p1;
        if (e == arr[p2])
            return p2;
        if (e < arr[p1])
            hi = p1 - 1;
        else if (e > arr[p2])
            lo = p2 + 1;
        else
        {
            lo = p1 + 1;
            hi = p2 - 1;
        }
    }
    return -1;
}
int main()
{
    int a[8] = {-35, -12, -1, 0, 6, 20, 42, 987}; //array should be sorted
    cout << ternary_search(a, 8, -12) << "\n";
    cout << ternary_search(a, 8, 2);
    return 0;
}