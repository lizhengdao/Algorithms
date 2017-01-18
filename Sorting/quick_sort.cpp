#include <iostream>
using namespace std;
template <typename T>
int partition(T arr[], int l, int h)
{
    T x = arr[h], temp;
    int i = l - 1, j;
    for (j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x) // <= for non-decreasing order, >= for non-increasing order
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;
    return (i + 1);
}
//generic quick sort function using templates
template <typename T>
void quicksort(T A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, h);
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}