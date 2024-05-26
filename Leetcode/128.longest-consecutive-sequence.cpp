#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    if (nums.size() == 0)
    {
        return 0;
    }

    if (nums.size() == 1)
        return 1;

    int curr = 1, currVal = nums[0], maxi = INT_MIN;

    for (int i = 1; i < nums.size(); i++)
    {
        if (arr[i] == currVal + 1)
        {
            curr++;
            currVal = arr[i];
        }
        else if (arr[i] == currVal)
        {
            continue;
        }
        else
        {
            maxi = max(curr, maxi);
            curr = 1;
            currVal = nums[i];
        }
    }

    return max(maxi, curr);
}

int main()
{

    return 0;
}