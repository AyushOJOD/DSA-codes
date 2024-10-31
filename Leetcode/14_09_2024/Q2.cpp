#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health});

        vector<vector<int>> vis(n, vector<int>(m, -1));
        vis[0][0] = health;

        while (!q.empty())
        {
            auto curr = q.front();
            int x = curr.first.first, y = curr.first.second;
            int currH = curr.second;
            q.pop();

            if (x == n - 1 && y == m - 1)
            {
                return currH >= 1;
            }

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    int newH = currH - grid[newX][newY];

                    if (newH > 0 && newH > vis[newX][newY])
                    {
                        vis[newX][newY] = newH;
                        q.push({{newX, newY}, newH});
                    }
                }
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}