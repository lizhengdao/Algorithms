#include <iostream>
using namespace std;
#define range 10 //range for integers is 10 as digits range from 0-9
void countsort(int arr[], int n, int place)
{
    int i, freq[range] = {0};
    int output[n];
    for (i = 0; i < n; i++)
        freq[(arr[i] / place) % range]++;
    for (i = 1; i < range; i++)
        freq[i] += freq[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[freq[(arr[i] / place) % range] - 1] = arr[i];
        freq[(arr[i] / place) % range]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
//radix sort function (only for integer types in range 0 to 100000)
void radixsort(int arr[], int n, int maxx) //maxx is the maximum element in the array
{
    int mul = 1;
    while (maxx)
    {
        countsort(arr, n, mul);
        mul *= 10;
        maxx /= 10;
    }
}
int main()
{
    int n, i, m = 0;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        m = max(a[i], m);
    }
    radixsort(a, n, m);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}