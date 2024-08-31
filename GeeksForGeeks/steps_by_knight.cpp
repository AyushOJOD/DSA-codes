#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> delRow = {-2, -2, -1, 1, 2, 2, 1, -1};
    vector<int> delCol = {-1, 1, 2, 2, 1, -1, -2, -2};

    int getNode(int row, int col, int N)
    {
        return row * N + col;
    }

    bool isValid(int row, int col, int N)
    {
        return (row >= 0 && row < N && col >= 0 && col < N);
    }

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        queue<pair<pair<int, int>, int>> q; //{{row, col}, steps};
        unordered_set<int> vis;             // {calculated node}

        q.push({{KnightPos[0], KnightPos[1]}, 0});
        vis.insert(getNode(KnightPos[0], KnightPos[1], N));

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int steps = curr.second;

            if (row == TargetPos[0] && col == TargetPos[1])
            {
                return steps;
            }

            for (int i = 0; i < 8; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (isValid(nRow, nCol, N) && vis.find(getNode(nRow, nCol, N)) == vis.end())
                {
                    q.push({{nRow, nCol}, steps + 1});
                    vis.insert(getNode(nRow, nCol, N));
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