#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int N, int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mini = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int oper = arr[i - 1] * arr[k] * arr[j] + helper(N, arr, i, k, dp) + helper(N, arr, k + 1, j, dp);

            mini = min(mini, oper);
        }

        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));

        return helper(N, arr, 1, N - 1, dp);
    }
};

int main()
{

    return 0;
}