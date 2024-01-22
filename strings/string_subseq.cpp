#include <bits/stdc++.h>
using namespace std;

bool subSeqRec(string &s1, string &s2, int m, int n)
{
    if (m == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return subSeqRec(s1, s2, m - 1, n - 1);
    }
    else
    {
        return subSeqRec(s1, s2, m, n - 1);
    }
}

bool isSubsequence(string &s1, string &s2)
{
    int i = 0;
    int j = 0;

    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return (j == s2.length());
}

int main()
{

    return 0;
}