#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty() || nums[st.top()] > nums[i])
            {
                st.push(i);
            }
        }

        int res = 0;

        for (int en = n - 1; en >= 0; en--)
        {
            while (!st.empty() && nums[st.top()] <= nums[en])
            {
                res = max(res, en - st.top());
                st.pop();
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}