#include <bits/stdc++.h>
#define LIMIT 1000000
using namespace std;
char buffer[LIMIT], *pos = buffer + LIMIT;
//fast IO using custom functions
inline char getnext()
{
    if (pos == buffer + LIMIT)
    {
        pos = buffer;
        fread(buffer, 1, LIMIT, stdin);
    }
    return *pos++;
}
inline long long getLong()
{
    long long num = 0;
    bool sign = 0;
    char cc;
    while (!isdigit(cc = getnext()))
    {
        if (cc == '-')
            sign = 1;
    }
    do
    {
        num = num * 10 + cc - '0';
    } while (isdigit(cc = getnext()));
    if (sign)
        return -num;
    else
        return num;
}
inline double getDouble()
{
    double num = 0, rest = 1;
    int sign = 1;
    char cc;
    while ((cc = getnext()) < '0' || cc > '9')
    {
        if (cc == '-')
            sign = -1;
    }
    do
    {
        num = num * 10 + cc - '0';
    } while ((cc = getnext()) >= '0' && cc <= '9');
    while ((cc = getnext()) >= '0' && cc <= '9')
    {
        rest /= 10;
        num += rest * (cc - '0');
    }
    return num * sign;
}

inline void getStr(char niz[])
{
    int i = 0;
    char cc;
    while (!isalnum(cc = getnext()))
        ;
    do
    {
        niz[i++] = cc;
    } while (isalnum((cc = getnext())));
    niz[i] = '\0';
}
int main()
{
    char ch = '0';
    long long i = 0;
    double d = 0.0;
    char str[10];
    ch = getnext();
    cout << ch << "\n";
    i = getLong();
    cout << i << "\n";
    d = getDouble();
    cout << d << "\n";
    getStr(str);
    cout << str << "\n";
    return 0;
}