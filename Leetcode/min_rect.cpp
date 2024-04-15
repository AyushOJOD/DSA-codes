#include <bits/stdc++.h>
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
{
    vector<pair<int, int>> v;
    for (auto it : points)
    {
        v.push_back({it[0], it[1]});
    }
    sort(v.begin(), v.end());

    int res = 1;
    int curr = v[0].first;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first <= curr + w)
        {
            continue;
        }
        else
        {
            res++;
            curr = v[i].first;
        }
    }
    return res;
}

int main()
{

    return 0;
}