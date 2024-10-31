#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N;

    int helper(vector<int> &nums, int idx, int prev, bool isInc)
    {
        if (idx == N)
        {
            return 0;
        }

        int maxLen1 = INT_MIN, maxLen2 = INT_MIN, m1 = INT_MIN, m2 = INT_MIN, n1 = INT_MIN, n2 = INT_MIN;

        if (isInc)
        {
            if (nums[idx] > nums[prev])
            {
                m1 = 1 + helper(nums, idx + 1, idx, 1);
            }
            else
            {
                m2 = 1 + helper(nums, idx + 1, prev, 0);
            }

            maxLen1 = max(m1, m2);
        }
        else
        {
            if (nums[idx] < nums[prev])
            {
                n1 = 1 + helper(nums, idx + 1, idx, 0);
            }
            else
            {
                n2 = 0;
            }

            maxLen2 = max(n1, n2);
        }

        return max(maxLen1, maxLen2);
    }

    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        N = n;

        return helper(nums, 0, -1, 1);
    }
};

int main()
{

    return 0;
}