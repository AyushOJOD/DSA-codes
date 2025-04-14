#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        unordered_map<string, int> rowCount;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            string key = "";
            for (int j = 0; j < n; j++)
            {
                key += to_string(grid[i][j]) + ",";
            }
            rowCount[key]++;
        }

        for (int i = 0; i < n; i++)
        {
            string key = "";
            for (int j = 0; j < n; j++)
            {
                key += to_string(grid[j][i]) + ",";
            }

            if (rowCount.find(key) != rowCount.end())
            {
                cnt += rowCount[key];
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}