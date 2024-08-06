#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rowFlips(vector<vector<int>> &grid, int row, int m)
    {
        int cnt = 0;

        for (int i = 0; i < m / 2; i++)
        {
            if (grid[row][i] != grid[row][m - i - 1])
            {
                cnt++;
            }
        }

        return cnt;
    }

    int flipCols(vector<vector<int>> &grid, int col, int n)
    {
        int cnt = 0;

        for (int i = 0; i < n / 2; i++)
        {
            if (grid[i][col] != grid[n - i - 1][col])
            {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int minFlips(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int RChange = 0, CChange = 0;

        for (int i = 0; i < n; i++)
        {
            RChange += rowFlips(grid, i, m);
        }

        for (int i = 0; i < m; i++)
        {
            CChange += flipCols(grid, i, n);
        }

        return min(RChange, CChange);
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid1

        return 0;
}