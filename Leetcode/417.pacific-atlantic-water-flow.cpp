#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int, int>> pacific;
        queue<pair<int, int>> atlantic;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            pacific.push({0, i});
            vis[0][i] = 1;

            atlantic.push({n - 1, i});
            vis[n - 1][i] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            if ((i != 0))
            {
                pacific.push({i, 0});
                vis[i][0] = 1;
            }
            if ((i != n - 1))
            {
                atlantic.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }

        // U L D R
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        unordered_set<pair<int, int>> pacificSet;
        unordered_set<pair<int, int>> atlanticSet;

        // Mark all the atlantic sewers
        while (!atlantic.empty())
        {
            auto it = atlantic.front();

            int row = it.first;
            int col = it.second;

            atlanticSet.insert({row, col});

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if ((isValid(nRow, nCol, n, m) && !vis[nRow][nCol] && heights[nRow][nCol] >= heights[row][col]))
                {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        vis = vector<vector<int>>();

        // Mark all the pacific sewers
        while (!pacific.empty())
        {
            auto it = pacific.front();

            int row = it.first;
            int col = it.second;

            pacificSet.insert({row, col});

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if ((isValid(nRow, nCol, n, m) && !vis[nRow][nCol] && heights[nRow][nCol] >= heights[row][col]))
                {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        vector<vector<int>> ans;

        for (auto it : pacificSet)
        {
            if (atlanticSet.find(it) != atlanticSet.end())
            {
                ans.push_back({it.first, it.second});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}