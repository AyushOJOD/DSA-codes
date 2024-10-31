#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getMaxOR(vector<int> &nums)
    {
        int maxOR = 0;

        for (int num : nums)
        {
            maxOR |= num;
        }
        return maxOR;
    }

    int helper(int idx, int currOR, vector<int> &nums, int maxOR)
    {

        if (idx == nums.size())
        {
            if (currOR == maxOR)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // Take
        int take = helper(idx + 1, currOR | nums[idx], nums, maxOR);

        // not Take
        int notTake = helper(idx + 1, currOR, nums, maxOR);

        return take + notTake;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();

        int maxOR = getMaxOR(nums);

        int currOR = 0;

        return helper(0, currOR, nums, maxOR);
    }
};

int main()
{

    return 0;
}