#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
private:
    vector<int> getNSR(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> NSR(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                NSR[i] = st.top();
            }

            st.push(i);
        }

        return NSR;
    }

    vector<int> getNSL(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> st;
        vector<int> NSL(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                NSL[i] = st.top();
            }

            st.push(i);
        }

        return NSL;
    }

    vector<int> getNGL(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> NGL(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                NGL[i] = st.top();
            }

            st.push(i);
        }

        return NGL;
    }

    vector<int> getNGR(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> NGR(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                NGR[i] = st.top();
            }

            st.push(i);
        }

        return NGR;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();

        ll sum = 0;

        vector<int> NGL = getNGL(nums);
        vector<int> NGR = getNGR(nums);
        vector<int> NSL = getNSL(nums);
        vector<int> NSR = getNSR(nums);

        for (int i = 0; i < n; i++)
        {
            ll greater = (i - NGL[i]) * (NGR[i] - i);
            ll smaller = (i - NSL[i]) * (NSR[i] - i);

            sum += ((greater - smaller) * nums[i]);
        }

        return sum;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3};

    Solution obj;

    cout << obj.subArrayRanges(nums);
    cout << obj.getSAMax(nums);
    cout << obj.getSAMin(nums);

    return 0;
}