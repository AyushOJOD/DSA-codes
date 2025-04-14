#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        unordered_map<int, int> mp;

        for (int num : candidates)
        {
            for (int i = 31; i >= 0; i--)
            {
                if ((num >> i) & 1 == 1)
                {
                    mp[i]++;
                }
            }
        }

        int maxLen = INT_MIN;

        for (auto &kv : mp)
        {
            maxLen = max(maxLen, kv.second);
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}