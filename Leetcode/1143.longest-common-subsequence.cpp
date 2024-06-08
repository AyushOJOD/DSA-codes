#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s1, string s2, int i, int j)
    {
        // Base case
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (s1[i] == s2[j])
        {
            return 1 + helper(s1, s2, i - 1, j - 1);
        }

        return max(helper(s1, s2, i - 1, j), helper(s1, s2, i, j - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {

        return helper(text1, text2, text1.length() - 1, text2.length() - 1);
    }
}

int
main()
{

    return 0;
}