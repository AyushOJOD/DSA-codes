#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 0)
        {
            return 0;
        }

        sort(points.begin(), points.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });

        int last = points[0][1];
        int res = 1;

        for (int i = 1; i < n; i++)
        {
            if (last < points[i][0])
            {
                res++;
                last = points[i][1];
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}