#include <iostream>
using namespace std;
//generic linear search in array
template <typename T>
int linear_search(const T arr[], const int size, const T e)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == e)
            return i;
    }
    return -1;
}
int main()
{
    int a[8] = {6, 0, -35, 42, -12, -1, 20, 987}; //array need not be sorted
    cout << linear_search(a, 8, -12) << "\n";
    cout << linear_search(a, 8, 2);
    return 0;
}