#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s, string t, int i, int j)
    {
        // Base case
        if (i < 0)
        {
            return j + 1;
        }

        if (j < 0)
        {
            return i + 1;
        }

        // recursion

        if (s[i] == t[j])
        {
            return 1 + helper(s, t, i - 1, j - 1);
        }

        int del1 = 1 + helper(s, t, i - 1, j);
        int del2 = 1 + helper(s, t, i, j - 1);

        return min(del1, del2);
    }

public:
    int minDistance(string word1, string word2)
    {
        return helper(word1, word2, word1.size() - 1, word2.length() - 1);
    }
};

int main()
{

    return 0;
}