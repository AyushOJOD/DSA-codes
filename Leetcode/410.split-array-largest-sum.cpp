#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int splits(vector<int> &nums, int sum)
    {
        int splits = 1, currSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (currSum + nums[i] <= sum)
            {
                currSum += nums[i];
            }
            else
            {
                splits++;
                currSum = nums[i];
            }
        }
        return splits;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int division = splits(nums, mid);

            if (division > k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{

    return 0;
}