#include <bits/stdc++.h>
using namespace std;

int maximumStrongPairXor(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }

    int maxXor = INT_MIN;

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = 0;

    while (left < nums.size() - 1)
    {
        for (int i = left; i < nums.size(); i++)
        {
            if (abs(nums[left] - nums[right]) <= nums[left])
            {
                int curr = nums[left] ^ nums[right];
                maxXor = max(maxXor, curr);
                right++;
            }
            else
            {
                break;
            }
        }
        left++;
        right = left;
    }
    return maxXor;
}

int main()
{

    cout << distributeCandies(5, 2);

    return 0;
}