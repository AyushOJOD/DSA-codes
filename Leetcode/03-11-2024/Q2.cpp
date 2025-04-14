#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<int> delRow = {0, 1, 0, -1};
        vector<int> delCol = {1, 0, -1, 0};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {dist, {row, col}}
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({moveTime[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int row = it.second.first;
            int col = it.second.second;
            int time = it.first;

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && (time + 1 < dist[nRow][nCol]) && time >= moveTime[nRow][nCol])
                {
                    dist[nRow][nCol] = time + moveTime[nRow][nCol];
                    pq.push({time + 1, {nRow, nCol}});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};

int main()
{

    return 0;
}