#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int P[MAX];
//Knuth-Morris-Pratt algorithm for string matching
//Complexity: O(N + M)

vector<int> KMP(string needle, string haystack)
{
    vector<int> matches;
    int i, j, n = haystack.size(), m = needle.size();
    for (i = 0; i < m; i++)
        P[i] = -1;
    for (i = 0, j = -1; i < m;)
    {
        while (j > -1 && needle[i] != needle[j])
            j = P[j];
        i++;
        j++;
        P[i] = j;
    }
    for (i = 0, j = 0; i < n;)
    {
        while (j > -1 && haystack[i] != needle[j])
            j = P[j];
        i++;
        j++;
        if (j == m)
        {
            matches.push_back(i - m);
            j = P[j];
        }
    }
    return matches;
}

int main()
{
    string haystack = "abcdmcbabcadccbdbcacscbababcdef", needle = "abc";
    vector<int> matches = KMP(needle, haystack);
    for (int i = 0; i < matches.size(); i++)
        cout << matches[i] << " ";
    cout << "\n";
    return 0;
}