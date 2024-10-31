#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int n = nums.size();

        vector<int> resRange = {-1000000, 1000000};
        priority_queue<P, vector<P>, greater<P>> pq; //{number, {listIdx, indexInList}}

        int maxEl = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i][0], {i, 0}});
            maxEl = max(maxEl, nums[i][0]);
        }

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int minEl = it.first;
            int listIdx = it.second.first;
            int indexInList = it.second.second;

            if (maxEl - minEl < resRange[1] - resRange[0])
            {
                resRange[1] = maxEl;
                resRange[0] = minEl;
            }

            if (indexInList + 1 < nums[listIdx].size())
            {
                int nextEl = nums[listIdx][indexInList + 1];
                pq.push({nextEl, {listIdx, indexInList + 1}});
                maxEl = max(maxEl, nextEl);
            }
            else
            {
                break;
            }
        }

        return resRange;
    }
};

int main()
{

    return 0;
}