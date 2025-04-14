#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        ll count = 0;

        function<ll(int, int)> helper = [&](int idx, int prev)
        {
            if (idx == n)
            {
                return 0LL;
            }

            ll take = 0;
            if (prev == -1 || abs(nums[idx] - nums[prev]) == 1)
            {
                prev = (nums[idx] + helper(idx + 1, idx)) % MOD;
            }

            ll notTake = helper(idx + 1, prev);

            return (take + notTake) % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            count = (count + helper(i, -1)) % MOD;
        }

        return count;
    }
};

int main()
{

    return 0;
}