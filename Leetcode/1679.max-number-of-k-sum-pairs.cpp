#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int res = 0;

        for (int x : nums)
        {
            int target = k - x;
            if (mp[target] > 0)
            {
                res++;
                mp[target]--;
            }
            else
            {
                mp[x]++;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}