#include <bits/stdc++.h>
using namespace std;

// 2,7,9,4,4

class Solution
{
private:
    int helper(vector<int> &piles, int isAlice, int idx, int m, vector<vector<vector<int>>> &dp)
    {
        int n = piles.size();

        if (idx >= n)
        {
            return 0;
        }

        if (dp[idx][m][isAlice] != -1)
        {
            return dp[idx][m][isAlice];
        }

        int maxStones = (isAlice) ? INT_MIN : INT_MAX;

        int currStones = 0;

        for (int x = 1; x <= min(2 * m, n - idx); x++)
        {
            if (idx + x - 1 < n)
            {
                currStones += piles[idx + x - 1];
            }

            if (isAlice)
            {
                maxStones = max(maxStones, currStones + helper(piles, 0, idx + x, max(m, x), dp));
            }
            else
            {
                maxStones = min(maxStones, helper(piles, 1, idx + x, max(m, x), dp));
            }
        }

        return dp[idx][m][isAlice] = maxStones;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        if (n == 1)
        {
            return piles[0];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return helper(piles, 1, 0, 1, dp);
    }
};

int main()
{

    return 0;
}