#include <bits/stdc++.h>
using namespace std;
// Bogosort (also known as permutation sort, stupid sort, slowsort, shotgun sort or monkey sort)
// The algorithm successively generates permutations of its input until it finds one that is sorted.
// Complextiy : Best case - O(n), Average Case - O(n!), Worst Case - O(∞)

// To check if array is sorted or not
template <typename T>
bool isSorted(T a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
}
// To generate permuatation of the array
template <typename T>
void shuffle(T a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
// Sorts array a[0..n-1] using Bogo sort
template <typename T>
void bogosort(T a[], int n)
{
    // if array is not sorted then shuffle the array again
    while (!isSorted(a, n))
        shuffle(a, n);
}
int main()
{
    int n = 12, a[] = {3, 2, -5, -1, 0, 4, -2, 1, 8, 10, -7, 12};
    cout << "Sorted array :\n";
    bogosort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}