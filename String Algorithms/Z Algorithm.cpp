#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;
//Z Algorithm for string matching
//Slozenost: O(N + M)
vector<int> Z_Algorithm(string needle, string haystack)
{
    string s = needle + "#" + haystack;
    int n = haystack.size(), m = needle.size(), len = s.size(), L = 0, R = 0;
    int Z[MAX_N]; // Z-Array
    vector<int> matches;
    for (int i = 1; i < len; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < len && s[R - L] == s[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            if (Z[i - L] < R - i + 1)
                Z[i] = Z[i - L];
            else
            {
                L = i;
                while (R < len && s[R - L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m)
            matches.push_back(i - m - 1);
    }
    return matches;
}

int main()
{
    string haystack = "abcdmcbabcadccbdbcacscbababcdef", needle = "abc";
    vector<int> matches = Z_Algorithm(needle, haystack);
    for (int i = 0; i < matches.size(); i++)
        cout << matches[i] << " ";
    cout << "\n";
    matches = Z_Algorithm("cd", "abcdbdca");
    for (int i = 0; i < matches.size(); i++)
        cout << matches[i] << " ";
    cout << "\n";
    return 0;
}