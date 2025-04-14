#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        bool isPossible = true;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (__builtin_popcount(nums[i]) != __builtin_popcount(nums[i + 1]))
                {
                    isPossible = false;
                    break;
                }
                else
                {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }

        return isPossible;
    }
};

int main()
{

    return 0;
}