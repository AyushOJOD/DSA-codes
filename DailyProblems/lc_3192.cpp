#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (cnt % 2 == 0)
            {
                if (nums[i] == 0)
                {
                    cnt++;
                }
            }
            else
            {
                if (nums[i] == 1)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}