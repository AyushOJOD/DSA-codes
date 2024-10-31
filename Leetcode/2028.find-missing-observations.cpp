#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int rollSum = 0;

        rollSum = accumulate(rolls.begin(), rolls.end(), rollSum);

        int total = (m + n) * mean, left = total - rollSum;

        if (left > 6 * n || left < n)
        {
            return {};
        }

        auto [q, r] = div(left, n);
        vector<int> ans(n, q);
        fill(ans.begin(), ans.begin() + r, q + 1);
        return ans;
    }
};

int main()
{

    return 0;
}