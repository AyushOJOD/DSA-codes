#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // curr -> city(max value: n)
    // idx -> day(max value: k)
    int helper(int curr, int idx, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore, vector<vector<int>> &dp)
    {
        if (idx >= K || curr >= N)
        {
            return 0;
        }

        if (dp[curr][idx] != -1)
        {
            return dp[curr][idx];
        }

        int stay = stayScore[idx][curr] + helper(curr, idx + 1, stayScore, travelScore, dp);

        int travel = INT_MIN;

        for (int j = 0; j < N; j++)
        {
            if (curr == j)
                continue;

            int temp = travelScore[curr][j] + helper(j, idx + 1, stayScore, travelScore, dp);
            travel = max(travel, temp);
        }

        return dp[curr][idx] = max(stay, travel);
    }

public:
    int N, K;

    int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore)
    {
        N = n;
        K = k;

        int ans = INT_MIN;

        vector<vector<int>> dp(n, vector<int>(k, -1));

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, helper(i, 0, stayScore, travelScore, dp));
        }

        return ans;
    }
};

int main()
{

    return 0;
}