#include <iostream>
using namespace std;
long long fibRecur(int n)
{
  if (n <= 1)
    return n;
  else
    return fibRecur(n - 1) + fibRecur(n - 2);
}
int main()
{
  cout << fibRecur(0) << "\n";
  cout << fibRecur(1) << "\n";
  cout << fibRecur(6) << "\n";
  cout << fibRecur(10) << "\n";
  return 0;
}