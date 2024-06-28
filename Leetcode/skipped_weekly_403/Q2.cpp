#include <bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int minRow = INT_MAX, maxRow = INT_MIN, minCol = INT_MAX, maxCol = INT_MIN;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == 1)
            {
                minRow = min(row, minRow);
                maxRow = max(row, maxRow);
                minCol = min(col, minCol);
                maxCol = max(col, maxCol);
            }
        }
    }

    int length = maxRow - minRow + 1;
    int breadth = maxCol - minCol + 1;

    return length * breadth;
}

int main()
{

    return 0;
}