#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    int swimInWater(vector<vector<int>> &grid)
    {
        priority_queue<pair<int, pair<int, int>>> pq; //{dist, {row, col}}
        pq.push({0, {0, 0}});
    }
};

int main()
{

    return 0;
}