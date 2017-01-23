#include <iostream>
#define MAX_N 5001
#define MAX_K 5001
using namespace std;
long long binom[MAX_N][MAX_K];
int lasti = 0, lastj = 0;
bool init = false;
/*  Algorithm to calculate (nCk) binomial coefficients (Pascal's Triangle)
    Complexity: O(n*k)
*/
long long BinomialCoefficient(const int n, const int k)
{
    if (lasti >= n && lastj >= k)
        return binom[n][k];
    if (!init)
    {
        for (int i = 0; i <= n; i++)
            binom[i][0] = 1;
        for (int j = 1; j <= k; j++)
            binom[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
            }
        }
        init = true;
        lasti = n;
        lastj = k;
        return binom[n][k];
    }
    else
    {
        if (lastj < k)
        {
            for (int i = 1; i <= lasti; i++)
            {
                for (int j = lastj + 1; j <= k; j++)
                {
                    binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
                }
            }
            lastj = k;
        }
        if (lasti >= n)
            return binom[n][k];
        else
        {
            for (int i = lasti + 1; i <= n; i++)
            {
                binom[i][0] = 1;
                for (int j = 1; j <= lastj; j++)
                {
                    binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
                }
            }
            lasti = n;
            return binom[n][k];
        }
    }
}

int main()
{
    cout << BinomialCoefficient(15, 2) << "\n";
    cout << BinomialCoefficient(5, 1) << "\n";
    cout << BinomialCoefficient(12, 3) << "\n";
    return 0;
}