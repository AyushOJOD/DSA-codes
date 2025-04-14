#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> delR = {0, -1, 0, 1};
    vector<int> delC = {1, 0, -1, 0};

    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //{currTime, {row, col}}

        pq.push({0, {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currTime = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if (row == n - 1 && col == m - 1)
            {
                return currTime;
            }

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delR[i];
                int nCol = col + delC[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol])
                {
                    int waitTime = ((grid[nRow][nCol] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime = max(currTime + 1, grid[nRow][nCol] + waitTime);

                    pq.push({nextTime, {nRow, nCol}});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}