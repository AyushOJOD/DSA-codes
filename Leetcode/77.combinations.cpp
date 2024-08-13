#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N, K;
    vector<vector<int>> result;
    unordered_set<int> st;

    void solve(vector<int> &nums, vector<int> &temp, int idx)
    {
        if (temp.size() == K)
        {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < N; i++)
        {
            if (st.find(nums[i]) == st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(nums, temp, idx, i);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        N = n;
        K = k;

        vector<int> nums;

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }

        vector<int> temp;

        solve(nums, temp, 0);

        return result;
    }
};

int main()
{

    return 0;
}