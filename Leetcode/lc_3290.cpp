#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long int ll;

    long long helper(vector<int> &a, vector<int> &b, int i, int j, vector<vector<long long>> &dp)
    {
        if (i == a.size())
        {
            return 0;
        }

        if (j >= b.size())
        {
            return -1e9;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        ll take = long long(a[i]) * long long(b[j]) + helper(a, b, i + 1, j + 1, dp);
        ll skip = helper(a, b, i, j + 1, dp);

        return dp[i][j] = max(take, skip);
    }

    long long maxScore(vector<int> &a, vector<int> &b)
    {
        vector<vector<long long int>> dp(4, vector<long long int>(b.size(), -1));

        return helper(a, b, 0, j, dp);
    }
};

int main()
{

    return 0;
}