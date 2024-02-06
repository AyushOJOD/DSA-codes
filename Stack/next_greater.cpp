#include <bits/stdc++.h>
using namespace std;

void next_greater(vector<int> &nums)
{
    stack<int> st;

    st.push(nums[nums.size() - 1]);

    cout << -1 << " ";

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        int ng = st.empty() ? -1 : st.top();

        cout << ng << " ";

        st.push(nums[i]);
    }
}

int main()
{

    vector<int> arr = {15, 10, 18, 12, 4, 6, 2, 8};

    next_greater(arr);
    return 0;
}