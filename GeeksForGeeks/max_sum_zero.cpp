#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    // Your code here
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}

int main()
{

    return 0;
}