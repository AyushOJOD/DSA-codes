#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    int k = st.size();

    vector<int> temp(st.begin(), st.end());

    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    }

    return k;
}

int main()
{

    return 0;
}