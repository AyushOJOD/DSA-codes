#include <bits/stdc++.h>
using namespace std;

vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
{
    unordered_map<string, vector<int>> mp;

    for (auto &i : access_times)
    {
        string name = i[0];
        int count = stoi(i[1].substr(0, 2)) * 60 + stoi(i[1].substr(2));
        mp[name].push_back(count);
    }

    vector<string> res;

    for (auto &times : mp)
    {
        vector<int> &ts = times.second;
        sort(ts.begin(), ts.end());

        int cnt = 1;
        for (int i = 1; i < ts.size(); i++)
        {
            if (ts[i] - ts[i - 1] <= 60)
            {
                cnt++;
                if (cnt >= 3)
                {
                    res.push_back(times.first);
                    break;
                }
            }
            else
            {
                cnt = 1;
            }
        }
    }

    return res;
};

int main()
{

    return 0;
}