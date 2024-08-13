#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        int n = nums.size();
        unordered_map<ll, ll> mp; // ID -> freq
        vector<ll> res;
        priority_queue<pair<ll, ll>> pq; // freq -> ID

        for (int i = 0; i < n; i++)
        {
            int id = nums[i];
            int f = freq[i];

            mp[id] += f;
            pq.push({mp[id], id});

            while (mp[pq.top().second] != pq.top().first)
            {
                pq.pop();
            }

            res[i] = pq.top().first;
        }

        return res;
    }
};

int main()
{

    return 0;
}