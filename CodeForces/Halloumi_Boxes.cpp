#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int k)
{
    if (k == 1 && !is_sorted(nums.begin(), nums.end()))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        solve(nums, k);
    }

    return 0;
}