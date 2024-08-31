#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> PSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                res[i] = arr[st.top()];
            }

            st.push(i);
        }

        return res;
    }

    vector<int> NSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                res[i] = arr[st.top()];
            }

            st.push(i);
        }

        return res;
    }

public:
    int findMaxDiff(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> pse = PSE(arr);

        int maxDiff = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int next_smaller = (nse[i] != -1) ? nse[i] : 0;
            int prev_smaller = (pse[i] != -1) ? pse[i] : 0;

            int diff = abs(next_smaller - prev_smaller);

            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};

int main()
{

    return 0;
}