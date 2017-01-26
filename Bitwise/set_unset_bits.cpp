#include <iostream>
using namespace std;
void set(long long &num, const int pos)
{
    num |= (1 << pos);
}
void unset(long long &num, const int pos)
{
    num &= (~(1 << pos));
}
void toggle(long long &num, const int pos)
{
    num ^= (1 << pos);
}
bool is_set(const long long num, const int pos)
{
    return num & (1 << pos);
}
int main()
{
    long long num = 7; //111 in binary
    int pos = 1;
    unset(num, pos); //101 now
    cout << num << "\n";
    set(num, pos); //111 again
    cout << num << "\n";
    pos = 3;
    toggle(num, 2); //011 now
    cout << num << "\n";
    cout << (is_set(num, 0) ? "Set" : "Unset") << "\n";
    return 0;
}