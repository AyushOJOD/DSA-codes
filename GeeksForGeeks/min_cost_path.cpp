#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(int row, int col, int n)
    {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        dp[0][0] = grid[0][0];

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (isValid(nRow, nCol, n))
                {
                    int cost = grid[nRow][nCol] + dp[row][col];

                    if (cost < dp[nRow][nCol])
                    {
                        dp[nRow][nCol] = cost;
                        q.push({nRow, nCol});
                    }
                }
            }

            return dp[n - 1][n - 1];
        }
    }
};

int main()
{

    return 0;
}