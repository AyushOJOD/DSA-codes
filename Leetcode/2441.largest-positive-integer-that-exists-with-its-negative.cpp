#include <bits/stdc++.h>
using namespace std;

int findMaxK(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    if (nums[0] > 0)
        return -1;

    int i = 0, j = nums.size() - 1;

    while (i < j)
    {
        if (abs(nums[i]) == nums[j])
        {
            return nums[j];
        }
        else if (abs(nums[i]) > nums[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return -1;
}

int main()
{

    return 0;
}