#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    map<int, int> cnt;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    bool fl = false;

    for (auto it : cnt)
    {
        fl |= (it.second & 1);
    }

    cout << (fl ? "YES" : "NO") << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}