#include <bits/stdc++.h>
using namespace std;

int searchIdx(vector<int> &nums, int target, bool isLeft)
{
    int left = 0;
    int right = nums.size() - 1;
    int idx = -1;

    while (left <= right)
    {

        int mid = left + (right - left) / 2;

        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            idx = mid;
            if (isLeft)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return idx;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int left = searchIdx(nums, target, true);
    int right = searchIdx(nums, target, false);

    return {left, right};
}

int main()
{

    return 0;
}