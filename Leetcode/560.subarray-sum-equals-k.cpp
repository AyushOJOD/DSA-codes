#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int k)
{
    int left = 0, right = 0, currSum = 0;

    while (right < nums.size())
    {
        currSum += nums[right];

        if (currSum > k)
        {
            currSum -= nums[left];
            left++;
        }
    }
}

int subarraySum(vector<int> &nums, int k)
{
}

int main()
{

    return 0;
}