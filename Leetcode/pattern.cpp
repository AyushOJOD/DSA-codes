#include <bits/stdc++.h>
using namespace std;

int countMatchingSubnumsays(vector<int> &nums, vector<int> &pattern)
{
    int n = nums.size();
    int m = pattern.size();
    int cntr = 0;

    for (int i = 0; i <= n - m - 1; ++i)
    {
        bool isMatch = true;
        for (int j = 0; j < m; ++j)
        {
            if ((pattern[j] == 1 && nums[i + j + 1] <= nums[i + j]) ||
                (pattern[j] == 0 && nums[i + j + 1] != nums[i + j]) ||
                (pattern[j] == -1 && nums[i + j + 1] >= nums[i + j]))
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
        {
            cntr++;
        }
    }

    return cntr;
}

int main()
{

    return 0;
}
