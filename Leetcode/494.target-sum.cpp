#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int target, int idx)
{
    if (idx == 0)
    {
        if (target - nums[idx] == 0)
        {
            return 1;
        }
        else if (target + nums[idx] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    for (int i = 0; i < idx; i++)
    {
    }
}

int findTargetSumWays(vector<int> &nums, int target)
{
}

int main()
{

    return 0;
}