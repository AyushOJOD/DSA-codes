#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> freqX(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> freqY(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 'X')
                {
                    freqX[i + 1][j + 1]++;
                }
                else if (grid[i][j] == 'Y')
                {
                    freqY[i + 1][j + 1]++;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                freqX[i][j] += freqX[i - 1][j] + freqX[i][j - 1] - freqX[i - 1][j - 1];
                freqY[i][j] += freqY[i - 1][j] + freqY[i][j - 1] - freqY[i - 1][j - 1];
            }
        }

        int result = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int x = freqX[i][j], y = freqY[i][j];
                if (x == y && x > 0 && y > 0)
                    result++;
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}