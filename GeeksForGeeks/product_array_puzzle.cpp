#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long int ll;

    vector<long long int> productExceptSelf(vector<long long int> &nums)
    {
        int n = nums.size();

        vector<ll> LtoR(n), RtoL(n), ans(n);

        LtoR[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            LtoR[i] = nums[i] * LtoR[i - 1];
        }

        RtoL[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            RtoL[i] = nums[i] * RtoL[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[i] = RtoL[i + 1];
            }
            else if (i == n - 1)
            {
                ans[i] = LtoR[i - 1];
            }
            else
            {
                ans[i] = LtoR[i - 1] * RtoL[i + 1];
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}