#include <iostream>
using namespace std;
//generic selection sort function using templates
template <typename T>
void selectionsort(T a[], const int n)
{
    int i, j, m; // m for min or max
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[m] > a[j]) // > for non-decreasing order, < for non-increasing order
                m = j;
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