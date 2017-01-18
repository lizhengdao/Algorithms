#include <iostream>
using namespace std;
//generic selection sort function using templates
template <typename T>
void selectionsort(T a[], T n)
{
    T i, j, m, temp; // m for min or max
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[m] > a[j])
                m = j; // > for non-decreasing order, < for non-increasing order
        }
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;
    }
}
int main()
{
    long long n, i;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    selectionsort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}