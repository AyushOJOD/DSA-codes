#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int atMostSum(vector<int> &nums, int goal)
    {
        int left = 0, right = 0, currSum = 0, count = 0;

        if (goal < 0)
        {
            return 0;
        }

        while (right < nums.size())
        {
            currSum += nums[right];

            if (currSum > goal)
            {
                currSum -= nums[left];
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        // subarrays with sum <= goal
        int lessthanGoal = atMostSum(nums, goal);
        int oneLessthanGoal = atMostSum(nums, goal - 1);

        return lessthanGoal - oneLessthanGoal;
    }
};

int main()
{

    return 0;
}