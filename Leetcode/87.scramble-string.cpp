#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(string s1, string s2, unordered_map<string, bool> &dp)
    {
        if (s1 == s2)
        {
            return true;
        }

        if (s1.length() != s2.length())
        {
            return false;
        }

        int n = s1.length();
        string key = s1 + "_" + s2;

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }

        bool result = false;

        for (int i = 1; i < n; i++)
        {
            bool swap = helper(s1.substr(0, i), s2.substr(n - i), dp) &&
                        helper(s1.substr(i), s2.substr(0, n - i), dp);

            if (swap)
            {
                result = true;
                break;
            }

            bool notSwap = helper(s1.substr(0, i), s2.substr(0, i), dp) &&
                           helper(s1.substr(i), s2.substr(i), dp);

            if (notSwap)
            {
                result = true;
                break;
            }
        }

        return dp[key] = result;
    }

public:
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> dp;
        return helper(s1, s2, dp);
    }
};

int main()
{

    return 0;
}