#include <iostream>
using namespace std;
//interpolation search in array
int interpolation_search(int arr[], int size, int e)
{   int lo=0,hi=size-1,mid;
    while(lo<=hi)
    {
        mid = lo + (((double)hi - lo) / (arr[hi] - arr[lo])) * (e - arr[lo]);
        if(arr[mid]>e)
            hi=mid;
        else if(arr[mid]<e)
            lo=mid;
        else
            return mid;
    }
    return -1;
}
int main()
{
    //array should be sorted and distribution of values should follow a uniform pattern.
    int a[8] = {-3,-2,-1,0,1,2,3,4};
    cout << interpolation_search(a, 8, -2) << "\n";
    cout << interpolation_search(a, 8, 3) << "\n";
    return 0;
}