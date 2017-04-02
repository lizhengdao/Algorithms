#include <iostream>
using namespace std;
int hamming_weight(int x)
{
    int count = 0;
    while(x)
    {
        count++;
        x &= x - 1;
    }
    return count;
}
int main()
{
    int a = 5;
    cout << "Hamming weight for " << a << " is " << hamming_weight(a);
    return 0;
}