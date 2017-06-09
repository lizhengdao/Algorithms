#include<iostream>
using namespace std;
long long maxSubArraySum(int a[], int n)
{
    long long max_so_far=a[0],curr_max=a[0];
    for(int i=0;i<n;i++)
    {
        curr_max=max((long long)a[i],curr_max+a[i]);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}
int main()
{
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    long long max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}