#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string s, unordered_set<string> &set, int i, vector<int> &dp)
    {
        if (i >= s.length())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int result = 1 + helper(s, set, i + 1, dp);

        for (int j = i; j < s.length(); j++)
        {
            string curr = s.substr(i, j - i + 1);

            if (set.find(curr) != set.end())
            {
                result = min(result, helper(s, set, j + 1, dp));
            }
        }

        return dp[i] = result;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> set(dictionary.begin(), dictionary.end());

        vector<int> dp(s.length(), -1);

        return helper(s, set, 0, dp);
    }
};

int main()
{

    return 0;
}