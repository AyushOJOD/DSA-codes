
// Divide the array into two subsequences such that the max value of the given seq

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max_val = 0;

        for (int i = 0; i <= n - 2 * k; ++i)
        {
            vector<int> seq(nums.begin() + i, nums.begin() + i + 2 * k);

            for (int mask = 0; mask < (1 << (2 * k)); ++mask)
            {
                if (__builtin_popcount(mask) == 2 * k)
                {
                    int a = 0, b = 0;
                    for (int j = 0; j < 2 * k; ++j)
                    {
                        if (mask & (1 << j))
                        {
                            if (j < k)
                                a |= seq[j];
                            else
                                b |= seq[j];
                        }
                    }
                    max_val = max(max_val, a ^ b);
                }
            }
        }

        return max_val + 1;
    }
};

int main()
{

    return 0;
}