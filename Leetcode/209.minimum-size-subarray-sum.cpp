#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        int left = 0, right = 0, currSum = 0, minLen = INT_MAX;

        while (right < n)
        {
            currSum += nums[right];

            while (sum >= target)
            {
                sum -= nums[left];
                minLen = min(minLen, j - i + 1);
                left++;
            }
            right++;
        }

        if (minLen == INT_MAX)
        {
            return 0;
        }

        return minLen;
    }
};

int main()
{

    return 0;
}