#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size(), prefixSum = 0;

    unordered_map<int, int> mp;
    mp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum = (prefixSum + nums[i]) % k;

        if (mp.find(prefixSum) != mp.end())
        {
            if (i + 1 - mp[prefixSum] >= 2)
            {
                return true;
            }
        }
        else
        {
            mp[prefixSum] = i + 1;
        }
    }

    return false;
}

int main()
{

    return 0;
}