#include <iostream>
using namespace std;
unsigned int countSetBits(long long n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
int main()
{
  long long i = 1023;
  cout << countSetBits(i);
}