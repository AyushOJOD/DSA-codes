#include <bits/stdc++.h>
using namespace std;

long long numberOfSubarrays(vector<int> &nums)
{
    long long ans = nums.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
}

int main()
{

    return 0;
}