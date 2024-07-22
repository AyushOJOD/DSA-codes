#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq; // {value, idx};

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        vector<pair<int, int>> v;

        for (int i = 0; i < k; i++)
        {
            v.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }

        sort(v.begin(), v.end());

        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};

int main()
{

    return 0;
}