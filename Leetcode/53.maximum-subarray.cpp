#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int curr = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        curr += nums[i];

        if (crr > maxSum)
        {
            maxSum = curr;
        }

        if (curr < 0)
        {
            curr = 0;
        }
    }
    return maxSum;
}

int main()
{

    return 0;
}