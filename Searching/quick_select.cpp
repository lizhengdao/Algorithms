#include <bits/stdc++.h>
using namespace std;
template <typename T>
//To select kth smallest element in array
//Complexity : O(n)
T quick_select(T arr[], const unsigned int k, const unsigned int li, const unsigned int hi)
{
    if (hi - li <= 1)
        return arr[k];
    int j = li;
    swap(arr[j], arr[k]);
    for (int i = j = li + 1; i < hi; i++)
    {
        if (arr[i] < arr[li])
            swap(arr[j++], arr[i]);
    }
    swap(arr[--j], arr[li]);
    if (k < j)
        return quick_select(arr, k, li, j);
    if (k > j)
        return quick_select(arr, k - j, j + 1, hi);
    return arr[j];
}

int main()
{
    int arr[] = {9, 1, 2, 4, 1};
    cout << quick_select(arr, 3, 0, 5) << "\n";
    return 0;
}