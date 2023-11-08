#include <bits/stdc++.h>
using namespace std;

int findChampion(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        bool isChamp = true;
        for (int j = 0; j < n; j++)
        {
            if (i != j && grid[j][i] == 1)
            {
                isChamp = false;
                break;
            }
        }
        if (isChamp)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    return 0;
}