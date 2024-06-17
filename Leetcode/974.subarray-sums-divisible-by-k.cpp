#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size(), prefixSum = 0;
    unordered_map<int, int> mp;
    int cnt = 0;

    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum = (prefixSum + (nums[i] % k) + k) % k;
        cnt += mp[prefixSum];
        mp[prefixSum]++;
    }

    return cnt;
}

int main()
{

    return 0;
}