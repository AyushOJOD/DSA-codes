#include <bits/stdc++.h>
using namespace std;

vector<int> minSubsequence(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    vector<int> res;
    int newSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        newSum += nums[i];
        sum -= nums[i];
        res.push_back(nums[i]);
        if (newSum > sum)
        {
            break;
        }
    }

    return res;
}

int main()
{

    vector<int> nums = {4, 3, 10, 9, 8};

    vector<int> res = minSubsequence(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}