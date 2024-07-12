#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // function to find number of subarray with <= k diffrent

    int helper(vector<int> &nums, int k)
    {
        int left = 0, right = 0, count = 0;

        if (k < 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        while (right < nums.size())
        {
            mp[nums[right]]++;

            while (mp.size() > k)
            {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};

int main()
{

    return 0;
}