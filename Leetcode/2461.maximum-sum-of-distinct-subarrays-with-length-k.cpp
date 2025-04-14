#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_set<int> unique;
        long long maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            while (unique.count(nums[right]))
            {
                currentSum -= nums[left];
                unique.erase(nums[left]);
                ++left;
            }

            unique.insert(nums[right]);
            currentSum += nums[right];

            if (right - left + 1 == k)
            {
                maxSum = max(maxSum, currentSum);
                currentSum -= nums[left];
                unique.erase(nums[left]);
                ++left;
            }
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}