#include <bits/stdc++.h>
using namespace std;

int minSubseqLen(string s1, string s2, int n, int m, int i, int j)
{
    // Base case
    if (i == 0 || j == 0)
    {
        return 0;
    }

    if (s1[i - 1] == s2[j - 1])
    {
        return 1 + minSubseqLen(s1, s2, n, m, i - 1, j - 1);
    }

    return max(minSubseqLen(s1, s2, n, m, i - 1, j), minSubseqLen(s1, s2, n, m, i, j - 1));
}

int minDistance(string word1, string word2)
{
}

int main()
{

    return 0;
}