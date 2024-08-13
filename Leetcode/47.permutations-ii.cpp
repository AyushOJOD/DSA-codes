#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> result;

    void solve(unordered_map<int, int> &mp, vector<int> &temp)
    {
        if (temp.size() == n)
        {
            result.push_back(temp);
            return;
        }

        for (auto &[num, count] : mp)
        {
            if (count == 0)
            {
                continue;
            }

            temp.push_back(num);
            mp[num]--;

            solve(mp, temp);

            mp[num]++;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int &num : nums)
        {
            mp[num]++;
        }

        n = nums.size();

        vector<int> temp;

        solve(mp, temp);

        return result;
    }
};

int main()
{

    return 0;
}