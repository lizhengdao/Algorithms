#include <iostream>
using namespace std;
//generic bubble sort function using templates
template <typename T>
void bubblesort(T a[], T n)
{
    T i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]) // > for non-decreasing order, < for non-increasing order
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
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
    bubblesort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}