#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        long long sum = 0, n = nums.size();

        for (int num : nums)
        {
            sum += num;
        }

        int target = sum % p;

        if (target == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        int prefixSum = 0;
        mp[0] = -1;

        int result = n;

        for (int i = 0; i < n; i++)
        {
            prefixSum = (prefixSum + nums[i]) % p;

            int left = (prefixSum - target + p) % p;

            if (mp.find(left) != mp.end())
            {
                result = min(result, (i - mp[left]));
            }

            mp[prefixSum] = i;
        }

        return result == n ? -1 : result;
    }
};

int main()
{

    return 0;
}