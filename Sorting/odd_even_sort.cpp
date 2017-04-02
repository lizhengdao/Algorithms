#include<bits/stdc++.h>
using namespace std;
// Odd-even sort (also known as brick sort)
// Complextiy : Best case - O(n), Worst Case - O(n^2)
//generic odd-even sort function using templates
template <typename T>
void odd_even_sort(T arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted
    while (!isSorted)
    {
        isSorted = true;
        // Perform Bubble sort on odd indexed element
        for (int i=1; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])  // > for non-decreasing order, < for non-increasing order
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }
        // Perform Bubble sort on even indexed element
        for (int i=0; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])  // > for non-decreasing order, < for non-increasing order
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    odd_even_sort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}