#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return true;
    }

    if (nums[left] != nums[right])
    {
        return false;
    }

    return f(nums, left + 1, right - 1);
}

bool isPalindrome(vector<int> &nums)
{
    return f(nums, 0, nums.size() - 1);
}

int main()
{

    return 0;
}