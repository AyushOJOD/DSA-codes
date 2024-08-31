#include <bits/stdc++.h>
using namespace std;

// yi + yj + |xi - xj|
// |xi - xj| <= k

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq; // {(yi-xi), xi}
        int n = points.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // Check : (xj - xi) > k
            while (!pq.empty() && (points[i][0] - pq.top().second) > k)
            {
                pq.pop();
            }

            if (!pq.empty())
            {
                ans = max(ans, (points[i][0] + points[i][1]) + pq.top().first);
            }

            pq.push({(points[i][1] - points[i][0]), points[i][0]});
        }

        return ans;
    }
};

int main()
{

    return 0;
}