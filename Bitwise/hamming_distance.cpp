#include <iostream>
using namespace std;
int hamming_distance(const int A, const int B)
{
    int diff = A ^ B, count = 0;
    while(diff)
    {
        count++;
        diff &= diff - 1;
    }
    return count;
}
int main()
{
    int a = 5, b = 6;
    cout << "Hamming distance between " << a << " and " << b << " is " << hamming_distance(a,b);
    return 0;
}