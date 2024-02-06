#include <bits/stdc++.h>
using namespace std;

void prev_greater_naive(int arr[], int n)
{
    // This will take O(n^2) time complexity
    // and will give reverse for obv reasons

    for (int i = n; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
    }
}

void prev_greater(vector<int> &nums)
{

    stack<int> st;
    st.push(nums[0]);

    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        int pg = st.empty() ? -1 : st.top();

        cout << pg << " ";

        st.push(nums[i]);
    }
}

int main()
{

    vector<int> arr = {15, 10, 18, 12, 4, 6, 2, 8};

    prev_greater(arr);

    return 0;
}