#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;
int count;

void helper(vector<int> &nums, int k, int idx)
{
    if (idx == nums.size())
    {
        count++;
        return;
    }

    int num = nums[idx];

    if (dp.find(num - k) == dp.end() && dp.find(num + k) == dp.end())
    {
        dp[num]++;
        helper(nums, k, idx + 1);
        dp[num]--;
        if (dp[num] == 0)
        {
            dp.erase(num);
        }
    }

    helper(nums, k, idx + 1);
}

int beautifulSubsets(vector<int> &nums, int k)
{
    count = 0;
    helper(nums, k, 0);
    return count - 1;
}

int main()
{

    vector<int> nums = {2, 4, 6};
    int k = 2;

    cout << beautifulSubsets(nums, k) << endl;

    return 0;
}