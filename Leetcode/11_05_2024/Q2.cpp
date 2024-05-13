#include <bits/stdc++.h>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();
    for (int i = 0; i < n; ++i)
    {
        points[i][0] = abs(points[i][0]);
        points[i][1] = abs(points[i][1]);
    }

    int l = 0;
    int r = 1e9;
    int res = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        unordered_map<char, int> mp;
        int f = 1;

        for (int i = 0; i < n; ++i)
        {
            if (points[i][0] <= mid && points[i][1] <= mid)
            {
                char c = s[i];
                mp[c]++;
            }
        }

        for (auto &it : mp)
        {
            if (it.second > 1)
            {
                f = 0;
                break;
            }
        }

        if (f == 1)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (points[i][0] <= res && points[i][1] <= res)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{

    return 0;
}