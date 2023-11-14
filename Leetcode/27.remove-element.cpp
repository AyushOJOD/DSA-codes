#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    if (nums.empty())
        return 0;

    int count = 0;
    int left = 0;
    int right = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[left] != val && left < right)
        {
            left++;
        }
        if (nums[right] != val && left < right)
        {
            right--;
        }

        if (nums[left] == val && nums[right] != val)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
            count += 2;
        }
    }

    return nums.size() - count;
}

int main()
{

    return 0;
}
