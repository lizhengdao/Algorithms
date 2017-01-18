#include <iostream>
using namespace std;
//generic insertion sort function using templates
template <typename T>
void insertionsort(T a[], T n)
{
    T i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--) // in a[j]>key : > for non-decreasing order, < for non-increasing order
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    insertionsort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}