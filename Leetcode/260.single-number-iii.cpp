#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cnt ^= nums[i];
    }

    unsigned int grp = cnt & -(unsigned int)cnt;

    int ans1 = 0,
        ans2 = 0;

    for (int x : nums)
    {
        if (x & grp)
        {
            ans1 ^= x;
        }
        else
        {
            ans2 ^= x;
        }
    }

    return {ans1, ans2};
}

int main()
{

    return 0;
}