#include <bits/stdc++.h>
using namespace std;

int sumCounts(vector<int> &nums)
{
    int size = nums.size();
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < size; j++)
        {
            st.insert(nums[j]);
            sum += st.size() * st.size();
        }
    }
    return sum;
}

int main()
{

    vector<int> nums = {1, 1};

    cout << sumCounts(nums);

    return 0;
}