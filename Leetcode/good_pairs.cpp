#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int count = 0;

    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }

    for (auto i : mp)
    {
        if (i.second > 1)
        {
            count += i.second;
        }
    }

    return count;
}

int main()
{

    return 0;
}