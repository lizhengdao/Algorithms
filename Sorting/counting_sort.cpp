#include <iostream>
using namespace std;
//counting sort function (only for integer types in range 0 to 100000)
void countingsort(int a[], int n)
{
    int i, j, no[100001] = {0};
    for (i = 0; i < n; i++)
    {
        no[a[i]]++;
    }
    j = 0;
    for (i = 0; i <= 100000; i++) // use for(i=100000;i>=0;i--) non-increasing order
    {
        while (no[i]--)
        {
            a[j] = i;
            j++;
        }
        if (j == n)
            break;
    }
}
int main()
{
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    countingsort(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}