#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(vector<vector<int>> &grid, int minRow, int maxRow, int minCol, int maxCol)
    {
        unordered_map<int, int> mp;

        int LRdiagonal = 0, RLdiagonal = 0;
        vector<int> colSum(3, 0), rowSum(3, 0);

        for (int row = minRow; row <= maxRow; row++)
        {
            for (int col = minCol; col <= maxCol; col++)
            {
                // 1-9 Check
                if (grid[row][col] < 1 || grid[row][col] > 9)
                {
                    return false;
                }

                // Distinct Check
                if (mp.find(grid[row][col]) != mp.end())
                {
                    return false;
                }
                else
                {
                    mp[grid[row][col]]++;
                }

                // Row Sum Check
                rowSum[row - minRow] += grid[row][col];

                // Col Sum Check
                colSum[col - minCol] += grid[row][col];

                // l-R Diagonal Check
                if (row - minRow == col - minCol)
                {
                    LRdiagonal += grid[row][col];
                }

                // R-L Diagonal Check
                if (row - minRow == 2 - (col - minCol))
                {
                    RLdiagonal += grid[row][col];
                }
            }
        }

        for (int i = 0; i < 2; i++)
        {
            if (rowSum[i] != rowSum[i + 1])
            {
                return false;
            }
            if (colSum[i] != colSum[i + 1])
            {
                return false;
            }
        }

        if ((LRdiagonal != rowSum[0]) || (RLdiagonal != rowSum[0]) || (rowSum[0] != colSum[0]))
        {
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (rows < 3 || cols < 3)
        {
            return 0;
        }

        int cnt = 0;

        for (int i = 0; i < (rows - 2); i++)
        {
            for (int j = 0; j < (cols - 2); j++)
            {
                if (isValid(grid, i, i + 2, j, j + 2))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}