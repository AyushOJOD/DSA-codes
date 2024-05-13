#include <bits/stdc++.h>
using namespace std;

int rowVal(vector<vector<int>> &grid, int row)
{
    int val = 0;
    int n = grid[row].size();

    for (int i = 0; i < n; i++)
    {
        val |= grid[row][i] << (n - i - 1);
    }

    return val;
}

void flipRow(vector<vector<int>> &grid, int row)
{
    for (int i = 0; i < grid[row].size(); i++)
    {
        grid[row][i] = 1 - grid[row][i];
    }
}

void flipCols(vector<vector<int>> &grid, int col)
{
    for (int i = 0; i < grid.size(); i++)
    {
        grid[i][col] = 1 - grid[i][col];
    }
}

int matrixScore(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Flip Rows

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            flipRow(grid, i);
        }
    }

    // Flip cols

    for (int i = 0; i < m; i++)
    {
        int zeros = 0, ones = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] == 1)
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        if (zeros > ones)
        {
            flipCols(grid, i);
        }
    }

    int maxVal = 0;

    for (int i = 0; i < n; i++)
    {
        maxVal += rowVal(grid, i);
    }

    return maxVal;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};

    cout << matrixScore(grid) << endl;

    return 0;
}