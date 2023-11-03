#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int minjump = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        minjump++;
        if (nums[i] >= minjump)
        {
            minjump = 0;
        }
    }

    return !minjump;
}

int main()
{

    return 0;
}