#include <bits/stdc++.h>
using namespace std;

int minimumDistance(vector<vector<int>> &points)
{
    int n = points.size();
    int t = 0;
    vector<int> res;
    while (t < n)
    {
        swap(points[t], points[n - 1]);
        int minsum, maxsum, mindiff, maxdiff;

        minsum = maxsum = points[0][0] + points[0][1];
        mindiff = maxdiff = points[0][0] - points[0][1];
        for (int i = 1; i < n - 1; i++)
        {
            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];
            if (sum < minsum)
                minsum = sum;
            else if (sum > maxsum)
                maxsum = sum;
            if (diff < mindiff)
                mindiff = diff;
            else if (diff > maxdiff)
                maxdiff = diff;
        }

        int maximum = max(maxsum - minsum, maxdiff - mindiff);
        res.push_back(maximum);
        swap(points[t], points[n - 1]);
        t++;
    }
    sort(res.begin(), res.end());
    return res[0];
}

int main()
{

    return 0;
}