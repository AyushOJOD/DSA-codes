#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000000007;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> leftMin(n, -1);
        vector<int> rightMin(n, n);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                leftMin[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i++)
        {
            while (!st.empty() && nums[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                rightMin[i] = st.top();
            }

            st.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += static_cast<ll>(i - leftMin[i]) * (rightMin[i]) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};

int main()
{

    return 0;
}