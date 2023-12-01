#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    for (int i = 0; i < mp.size(); i++)
    {
        if (mp[i] > n / 2)
            return i;
    }
}

int main()
{

    return 0;
}