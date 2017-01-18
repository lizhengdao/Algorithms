#include <iostream>
using namespace std;
//generic binary search in array
template <typename T>
int binary_search(T arr[], int size, T e)
{
    int lo = 0, hi = size - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (e > arr[mid])
            lo = mid + 1;
        else if (e < arr[mid])
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int a[8] = {-35, -12, -1, 0, 6, 20, 42, 987};   //array should be sorted
    cout << binary_search(a, 8, -12) << "\n";
    cout << binary_search(a, 8, 2);
    return 0;
}