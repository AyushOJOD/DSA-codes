#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &nums)
{
    int totalSum = 0;

    vector<vector<int>> res;

    int n = nums.size();

    for (int it : nums)
    {
        totalSum += it;
    }

    int currSum = 0, idx = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];

        if (currSum + currSum == totalSum)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        return idx;
    }

    vector<int> temp;

    for (int i = 0; i < idx; i++)
    {
        temp.push_back(nums[i]);
    }

    res.push_back(temp);

    temp.clear();

    for (int i = idx; i < n; i++)
    {
        temp.push_back(nums[i]);
    }

    res.push_back(temp);

    return res;
}

int main()
{

    return 0;
}