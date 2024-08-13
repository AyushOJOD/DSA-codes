#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int totalCells = rows * cols;
        int directionIdx = 0;
        int steps = 1;

        result.push_back({rStart, cStart});
        if (totalCells == 1)
        {
            return result;
        }

        while (result.size() < totalCells)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < steps; j++)
                {
                    rStart += directions[directionIdx][0];
                    cStart += directions[directionIdx][1];

                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    {
                        result.push_back({rStart, cStart});
                        if (result.size() == totalCells)
                        {
                            return result;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}