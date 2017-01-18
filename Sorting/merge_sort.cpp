#include <iostream>
using namespace std;
template <typename T>
void merge(T arr[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    T L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) // <= for non-decreasing order, >= for non-increasing order
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//generic merge sort function using templates
template <typename T>
void mergesort(T arr[], int l, int r)
{
    if (l < r)
    {
        int m = (r + l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}