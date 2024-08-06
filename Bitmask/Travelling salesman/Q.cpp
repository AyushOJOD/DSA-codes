// Q : https://codeforces.com/problemset/problem/1503/C
// Q : https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

/*
    Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

    Input: cost = {{0,111},{112,0}}
    Output: 223

    Input: cost = {{0,1000,5000},{5000,0,1000},
    {1000,5000,0}}
    Output: 3000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &cost, int mask, int idx, int n, vector<vector<int>> &dp)
    {
        if (mask == (1 << n) - 1) // All of the places are visited
        {
            return cost[idx][0];
        }

        if (dp[idx][mask] != -1)
        {
            return dp[idx][mask];
        }

        int ans = INT_MAX;

        for (int j = 0; i < n; j++)
        {
            if ((mask & (1 << j)) == 0)
            {
                ans = min(ans, cost[idx][j] + solve(cost, (mask | (1 << j)), j, n, dp));
            }
        }

        return dp[idx][mask] = ans;
    }

public:
    int total_cost(vector<vector<int>> cost)
    {
        // Code here
        int n = cost.size();

        vector<vector<int>> dp(n, vector<int>((1 << n), -1));

        return solve(cost, (1 << n), 0, n, dp);
    }
};

int main()
{

    return 0;
}