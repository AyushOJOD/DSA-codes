#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &nums, int val)
{
    int cnt = 0;
    for (int x : nums)
    {
        if (x >= val)
        {
            cnt++;
        }
    }
    return cnt;
}

int specialArray(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cnt = count(nums, nums[mid]);

        if (cnt == nums[mid])
        {
            return nums[mid];
        }
        else if (cnt < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}