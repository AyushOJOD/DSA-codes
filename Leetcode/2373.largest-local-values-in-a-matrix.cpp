#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &grid, int minRow, int maxRow, int minCol, int maxCol)
{
    int maxVal = INT_MIN;

    for (int i = minRow; i < maxRow; i++)
    {
        for (int j = minCol; j < maxCol; j++)
        {
            maxVal = max(maxVal, grid[i][j]);
        }
    }

    return maxVal;
}

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));

    for (int i = 0; i < n; i = i + 3)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}

int main()
{

    return 0;
}