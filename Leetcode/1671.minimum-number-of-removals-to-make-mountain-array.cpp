#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> LIS(n, 0), LDS(n, 0);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && LIS[i] < LIS[j] + 1)
                {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j >= i; j--)
            {
                if (nums[j] < nums[i] && LDS[i] < LDS[j] + 1)
                {
                    LDS[i] = LDS[j] + 1;
                }
            }
        }

        int maxval = 0;

        for (int i = 0; i < n; i++)
        {
            if (LIS[i] > 0 && LDS[i] > 0)
            {
                maxVal = max(maxval, LDS[i] + LIS[i]);
            }
        }

        return n - maxval - 1;
    }
};

int main()
{

    return 0;
}