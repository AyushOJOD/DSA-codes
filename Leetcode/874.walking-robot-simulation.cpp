#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<string> danger;

        for (auto &obstacle : obstacles)
        {
            danger.insert(to_string(obstacle[0]) + '|' + to_string(obstacle[1]));
        }

        int row = 0, col = 0, dirX = 0, dirY = 1;
        int distance = 0;

        for (int payload : commands)
        {
            if (payload == -1)
            {
                int curr = dirX;
                dirX = dirY, dirY = -curr;
            }
            else if (payload == -2)
            {
                int curr = dirX;
                dirX = -dirY, dirY = curr;
            }
            else
            {
                for (int i = 0; i < payload; i++)
                {
                    int nRow = row + dirX;
                    int nCol = col + dirY;

                    if (danger.find(to_string(nRow) + '|' + to_string(nCol)) != danger.end())
                    {
                        break;
                    }
                    row = nRow;
                    col = nCol;
                    distance = max(distance, row * row + col * col);
                }
            }
        }

        return distance;
    }
};

int main()
{

    return 0;
}