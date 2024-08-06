/*
Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &cost, vector<vector<int>> &dp, int mask, int idx)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][mask] != -1)
    {
        return dp[idx][mask];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            ans = min(ans, cost[i][idx] + solve(n, cost, dp, (mask ^ (1 << i)), idx + 1));
        }
    }

    return dp[idx][mask] = ans;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> dp(21, vector<int>((1 << 21), -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << solve(n, cost, dp, (1 << n) - 1, 0);

    return 0;
}