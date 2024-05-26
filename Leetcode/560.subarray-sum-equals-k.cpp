#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int sum = 0, cnt = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
            cnt++;

        if (mp.find(sum - k) != mp.end())
        {
            cnt += mp[sum - k];
        }

        mp[sum]++;
    }

    return cnt;
}

int main()
{

    return 0;
}