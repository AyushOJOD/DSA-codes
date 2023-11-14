#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();

    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {

        mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return mid;
}

int main()
{

    return 0;
}