#include <bits/stdc++.h>
using namespace std;

// For every value in the bottom you have only one possible answer
class Solution
{

private:
    bool isValid(int row, int col, int m, int n)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    int helper(vector<vector<int>> &matrix, int row, int col, int m, int n, vector<vector<int>> &dp)
    {
        // base case
        if (row == 0)
        {
            return matrix[row][col];
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // recursion
        int up = INT_MAX, rightDiag = INT_MAX, leftDiag = INT_MAX;

        up = matrix[row][col] + helper(matrix, row - 1, col, m, n, dp);

        if (isValid(row - 1, col + 1, n, m))
        {
            rightDiag = matrix[row][col] + helper(matrix, row - 1, col + 1, m, n, dp);
        }

        if (isValid(row - 1, col - 1, m, n))
        {
            leftDiag = matrix[row][col] + helper(matrix, row - 1, col - 1, m, n, dp);
        }

        return dp[row][col] = min(up, min(rightDiag, leftDiag));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        // base case
        for (int col = 0; col < m; col++)
        {
            prev[col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                int up = INT_MAX, rightDiag = INT_MAX, leftDiag = INT_MAX;

                up = matrix[row][col] + prev[col];

                if (isValid(row - 1, col + 1, n, m))
                {
                    rightDiag = matrix[row][col] + prev[col + 1];
                }

                if (isValid(row - 1, col - 1, m, n))
                {
                    leftDiag = matrix[row][col] + prev[col - 1];
                }

                curr[col] = min(up, min(rightDiag, leftDiag));
            }
            prev = curr;
        }

        int minValue = INT_MAX;

        for (int i = 0; i < m; i++)
        {
            minValue = min(minValue, prev[i]);
        }

        return minValue;
    }
};

int main()
{

    return 0;
}