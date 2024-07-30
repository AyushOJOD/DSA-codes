#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s, string t, int i, int j)
    {
        if (j >= t.length())
        {
            return s.length() - 1;
        }

        if (s.length() <= i)
        {
            return t.length() - j;
        }

        if (s[i] == t[j])
        {
            return helper(s, t, i + 1, j + 1);
        }

        int del = 1 + helper(s, t, i + 1, j);
        int ins = 1 + helper(s, t, i, j + 1);
        int replace = 1 + helper(s, t, i + 1, j + 1);

        return min({del, ins, replace});
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        if (n == 0 || m == 0)
        {
            max(n, m);
        }

        return helper(word1, word2, 0, 0);
    }
};

int main()
{

    return 0;
}