#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    int MOD = 100000;

    vector<int> dist(100000, 1e9);
    queue<pair<int, int>> q; // {number, steps}

    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty())
    {
        int num = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int value = (it * num) % MOD;
            if (dist[value] > 1 + steps)
            {
                dist[value] = 1 + steps;
                if (value == end)
                {
                    return 1 + steps;
                }
                q.push({value, steps + 1});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}