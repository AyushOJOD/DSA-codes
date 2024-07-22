#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int helper(vector<int> &nums, int div)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return ceil(float(sum / div));
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1, right = threshold, minValue = INT_MAX;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int value = helper(nums, mid);

            if (value > threshold)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{

    return 0;
}