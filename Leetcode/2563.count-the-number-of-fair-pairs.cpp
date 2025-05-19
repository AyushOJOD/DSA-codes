#include <bits/stdc++.h>
using namespace std;

// lower - nums[i] <= nums[j] <= upper - nums[i]

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());

        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            int left = lower - nums[i];
            int right = upper - nums[i];

            int l = lower_bound(nums.begin() + 1 + i, nums.end(), left) - nums.begin();
            int r = upper_bound(nums.begin() + 1 + i, nums.end(), right) - nums.begin();

            count += (r - l);
        }

        return count;
    }
};

int main()
{

    return 0;
}