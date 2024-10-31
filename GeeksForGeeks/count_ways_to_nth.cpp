#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int idx, int n, vector<int> &dp)
    {
        if (idx == n)
        {
            return 0;
        }

        if (idx == n - 1)
        {
            return 1;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        return dp[idx] = helper(idx + 1, n, dp) + helper(idx + 2, n, dp);
    }

public:
    int nthStair(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(0, n, dp);
    }
};

int main()
{

    return 0;
}