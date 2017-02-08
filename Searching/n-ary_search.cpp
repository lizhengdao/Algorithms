#include <iostream>
using namespace std;
// Complextiy : O((n-1)log(N))  where N = no of elements in array, n = no of midpoints (n-ary search)
// generic n-ary search in array
template <typename T>
int nary_search(const T arr[], const int size, const T e, int n)
{
    if (n < 2)
        return -1;
    if (n > size)
        n = size;
    int i, lo = 0, hi = size - 1, mid[n - 1];
    while (lo <= hi)
    {
        for (i = 0; i < n; i++)
            mid[i] = lo + ((i + 1) * (hi - lo)) / (n + 1);
        for (i = 0; i < n; i++)
        {
            if (arr[mid[i]] < e)
                lo = mid[i] + 1;
            else if (arr[mid[i]] > e)
            {
                hi = mid[i] - 1;
                break;
            }
            else
                return mid[i];
        }
    }
    return -1;
}
int main()
{
    int a[8] = {-35, -12, -1, 0, 6, 20, 42, 987}; //array should be sorted
    cout << nary_search(a, 8, -12, 2) << "\n";  //n=2 =>binary search
    cout << nary_search(a, 8, 2, 4) << "\n";    //n=4 =>quaternary search
    return 0;
}