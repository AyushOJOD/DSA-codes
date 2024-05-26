#include <bits/stdc++.h>
using namespace std;

int total(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int xr = 0;
    mp[xr]++; //{0, 1}
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xr = xr ^ nums[i];
        int req = xr ^ k;
        cnt += mp[req];
        mp[xr]++;
    }

    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    cout << total(a, k);

    return 0;
}