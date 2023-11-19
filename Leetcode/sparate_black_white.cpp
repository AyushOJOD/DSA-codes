#include <bits/stdc++.h>
using namespace std;

long long minimumSteps(string s)
{
    long long zero = 0;
    for (auto i : s)
    {
        if (i == '0')
            zero++;
    }
    long long i = 0;
    long long current = 0, res = 0;
    while (i < s.size())
    {
        if (s[i] == '0')
        {
            res = res + i - current;
            current++;
        }
        i++;
    }
    return res;
}

int main()
{

    return 0;
}
