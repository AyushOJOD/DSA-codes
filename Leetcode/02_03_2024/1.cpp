#include <bits/stdc++.h>
using namespace std;

long long numberOfRightTriangles(vector<vector<int>> &grid)
{
    vector<int> r(grid[0].size());
    vector<int> u(grid.size());
    for (int i = 0; i < u.size(); i++)
    {
        u[i] = count(grid[i].begin(), grid[i].end(), 1);
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        int ct = 0;
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i])
            {
                ct++;
            }
        }
        r[i] = ct;
    }
    long long ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j])
            {
                ans += ((r[j] - 1) * (u[i] - 1));
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}