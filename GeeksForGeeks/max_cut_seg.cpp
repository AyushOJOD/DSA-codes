#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n < 0)
        {
            return INT_MIN;
        }
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int Xcut = helper(n - x, x, y, z, dp);
        int Ycut = helper(n - y, x, y, z, dp);
        int Zcut = helper(n - z, x, y, z, dp);

        int maxCuts = max({Xcut, Ycut, Zcut});

        return dp[n] = (maxCuts == INT_MIN) ? INT_MIN : 1 + maxCuts;
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        int result = helper(n, x, y, z, dp);
        return result < 0 ? 0 : result;
    }
};

int main()
{

    return 0;
}