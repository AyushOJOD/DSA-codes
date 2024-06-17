#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> mp;

    for (auto x : arr1)
    {
        mp[x]++;
    }

    vector<int> ans;

    for (auto it : arr2)
    {
        while (mp[it]--)
        {
            ans.push_back(it);
        }
    }

    for (auto &[k, v] : mp)
    {
        while (v-- && v > 0)
        {
            ans.push_back(k);
        }
    }

    return ans;
}

int main()
{

    return 0;
}