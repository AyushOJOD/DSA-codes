#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();

    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int left = 1, right = n - 2;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return mid;
        }
        if (nums[mid] == nums[mid + 1])
        {
            right = mid - 2;
        }
        else
        {
            left = mid + 2;
        }
    }
}

int main()
{

    return 0;
}