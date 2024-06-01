#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    swap(nums[left], nums[right]);
    f(nums, left + 1, right - 1);
}

vector<int> reversed(vector<int> &nums)
{
    f(nums, 0, nums.size() - 1);

    return nums;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    cout << reversed(nums);

    return 0;
}