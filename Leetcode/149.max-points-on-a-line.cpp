#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int mx = 0;

        for (auto &p1 : points)
        {
            unordered_map<double, int> freq;
            for (auto &p2 : points)
            {
                double slope = INT_MIN;

                if (p1 == p2)
                    continue;

                if (p1[0] != p2[0])
                    slope = (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);

                mx = max(mx, ++freq[slope]);
            }
        }

        return mx + 1;
    }
};

int main()
{

    return 0;
}