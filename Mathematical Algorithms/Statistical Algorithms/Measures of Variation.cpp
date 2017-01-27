#include <bits/stdc++.h>
using namespace std;
//function to calculate range for given set of numeric data
template <typename T>
double range(T arr[], int start, int end)
{
    double max = arr[start], min = arr[start];
    for (int i = start; i < end; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    return max - min;
}
//function to calculate variance with respect to given mean for given range of numeric data types
template <typename T>
double variance(T arr[], int start, int end, double mean)
{
    double temp, sum = 0;
    for (int i = start; i < end; i++)
    {
        temp = mean - arr[i];
        sum += (temp * temp);
    }
    return sum / (end - start);
}
//function to calculate standard deviation with respect to given mean for given range of numeric data types
template <typename T>
double standard_deviation(T arr[], int start, int end, double mean)
{
    return sqrt(variance(arr, start, end, mean));
}
int main()
{
    int i, n = 10;
    int arr[] = {1, 2, 3, 4, 4, 6, 7, 8, 8, 10};
    cout << "Range = " << range(arr, 0, n) << "\n";
    cout << "Variance with respect to 5 = " << variance(arr, 0, n, 5) << "\n";
    cout << "Standard Deviation with respect to 5 = " << standard_deviation(arr, 0, n, 5);
}