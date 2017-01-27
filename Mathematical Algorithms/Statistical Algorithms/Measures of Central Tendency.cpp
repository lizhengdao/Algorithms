#include <bits/stdc++.h>
using namespace std;
double q[3]; //array to store quartiles
//function to calculate mean for given range of numeric data types
template <typename T>
double mean(T arr[], int start, int end)
{
    long double sum = 0;
    for (int i = start; i < end; i++)
        sum += arr[i];
    return sum / (end - start);
}
//function to calculate median for given range of numeric data types
template <typename T>
double median(T arr[], int start, int end) //arr must be sorted
{
    int n = end - start;
    if (n % 2)
        return arr[start + (n / 2)];
    else
        return (arr[start + ((n - 1) / 2)] + arr[start + (n / 2)]) / 2.0;
}
//generic function to mode for given range of data
template <typename T>
T mode(T arr[], int start, int end) //arr must be sorted
{
    int i, count = 1, countMode = 1;
    T no = arr[start], mode = arr[0];
    for (i = start + 1; i < end; i++)
    {
        if (no == arr[i])
            count++;
        else
        {
            if (count > countMode)
            {
                countMode = count;
                mode = no;
            }
            no = arr[i];
            count = 1;
        }
    }
    return mode;
}
//function to calculate quartile points for given range of numeric data types
template <typename T>
double *quartiles(T arr[], int start, int end, double *q) //arr must be sorted
{
    int n = end - start;
    q[1] = median(arr, start, end);
    if (n % 2)
    {
        q[0] = median(arr, start, start + ((n - 1) / 2));
        q[2] = median(arr, start + ((n + 1) / 2), end);
    }
    else
    {
        q[0] = median(arr, start, start + (n / 2));
        q[2] = median(arr, start + (n / 2), end);
    }
    return q;
}
template <typename T>
double interquartile_range(T arr[], int start, int end)
{
    quartiles(arr, start, end, q);
    return q[2] - q[0];
}
int main()
{
    int i, n = 10;
    int arr[] = {1, 2, 3, 4, 4, 6, 7, 8, 8, 10};
    sort(arr, arr + n);
    cout << "\nMean = " << mean(arr, 0, n) << "\nMedian = " << median(arr, 0, n) << "\nMode = " << mode(arr, 0, n) << "\n";
    quartiles(arr, 0, n, q);
    cout << "Q1 = " << q[0] << ", Q2 = " << q[1] << ", Q3 = " << q[2] << "\n";
    cout << "Interquartile range = " << q[2] - q[0];
}