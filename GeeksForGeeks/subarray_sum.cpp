#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subArraySum(vector<int> &arr, int tar)
    {
        unordered_map<int, int> mp; //{sum -> freq}

        int currSum = 0;
        int cnt = 0;

        mp[0] = 1;

        for (int num : arr)
        {
            currSum += num;

            if (mp.find(currSum - tar) != mp.end())
            {
                cnt += mp[currSum - tar];
            }

            mp[currSum - tar]++;
        }

        return cnt;
    }
};

int main()
{

    return 0;
}