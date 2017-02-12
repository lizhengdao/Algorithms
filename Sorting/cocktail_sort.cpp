#include <bits/stdc++.h>
using namespace std;
//cocktail sort (also known as bidirectional bubble sort, cocktail shaker sort, martini sort, ripple sort, shuffle sort, or shuttle sort)
//The algorithm differs from bubble sort in that it sorts in both directions on each pass through the list
//Complexity : O(n^2)
//generic bubble sort function using templates
template <typename T>
void cocktailsort(T a[], int n)
{
    bool sorted = false;
    int start = 0, end = n - 1, i;
    while (!sorted)
    {
        sorted = true;
        for (i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1]) // > for non-decreasing order, < for non-increasing order
            {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
        sorted = true;
        --end;
        for (i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) // > for non-decreasing order, < for non-increasing order
            {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
        ++start;
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cocktailsort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}