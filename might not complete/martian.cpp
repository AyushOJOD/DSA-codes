#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<pair<int, int>>> &grid, int row, int col)
{
}

int solve(vector<vector<pair<int, int>>> &grid)
{
}

int main()
{

    int n, m;

    while (true)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }

        vector<vector<pair<int, int>>> grid(n, vector<pair<int, int>>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j].first;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j].second;
            }
        }

        cout << solve(grid);
    }

    return 0;
}