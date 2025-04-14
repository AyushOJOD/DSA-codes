#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     vector<int> helper(vector<int> &nums, bool isStart)
    //     {
    //         vector<int> res;

    //         for (int i = 0; i < nums.size(); i++)
    //         {
    //             if (isStart)
    //             {

    //             }
    //         }
    //     }

public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> LtoR(n, 1), RtoL(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                LtoR[i] = nums[i];
            }
            else
            {
                LtoR[i] = LtoR[i - 1] * nums[i];
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                RtoL[i] = nums[i];
            }
            else
            {
                RtoL[i] = RtoL[i + 1] * nums[i];
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                res[i] = RtoL[i + 1];
            }
            else if (i == n - 1)
            {
                res[i] = LtoR[n - 2];
            }
            else
            {
                res[i] = LtoR[i - 1] * RtoL[i + 1];
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}