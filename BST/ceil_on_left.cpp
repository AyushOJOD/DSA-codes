#include <bits/stdc++.h>
using namespace std;

void ceil_on_left(vector<int> &nums)
{
    int n = nums.size();

    cout << -1 << " ";

    set<int> s;
    s.insert(nums[0]);

    for (int i = 1; i < n; i++)
    {
        auto it = s.lower_bound(nums[i]);
        if (it == s.begin())
        {
            cout << -1 << " ";
        }
        else
        {
            it--;
            cout << *it << " ";
        }
        s.insert(nums[i]);
    }

    cout << endl;
}

int main()
{

    return 0;
}