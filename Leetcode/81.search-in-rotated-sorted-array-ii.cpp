#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[mid] == nums[left] && nums[mid] == nums[right])
        {
            right--;
            left++;
        }
        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[right] >= target && nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}