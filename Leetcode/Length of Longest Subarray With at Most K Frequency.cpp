#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int res = 0;

    for (int i = 0, j = 0; j < nums.size(); j++)
    {
        mp[nums[j]]++;
        while (mp[nums[i]] > k)
        {
            mp[nums[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
    }
    return res;
}

int main()
{

    return 0;
}