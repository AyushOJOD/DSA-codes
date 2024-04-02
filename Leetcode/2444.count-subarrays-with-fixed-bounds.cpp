#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    long long ans = 0;
    int n = nums.size();
    int left = -1, right = -1, unBound = -1;

    for (int i = 0; i < n; i++)
    {
        if (!(nums[i] >= minK && nums[i] <= maxK))
        {
            unBound = i;
        }
        if (nums[i] == minK)
        {
            left = i;
        }
        if (nums[i] == maxK)
        {
            right = i;
        }

        if (left != -1 && right != -1)
        {
            ans += max(0, min(right, left) - unBound);
        }
    }

    return ans;
}

int main()
{

    return 0;
}