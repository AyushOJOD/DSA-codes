#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        p1.second < p2.second;
    }

    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        // Your code here
        int n = arr.size();
        vector<pair<int, int>> data;

        for (int i = 0; i < n; i++)
        {
            data.push_back({arr[i], dep[i]});
        }

        sort(data.begin(), data.end(), comp);

        int cnt = 1, leaveTime = data[0].second;
        }
};

int main()
{

    return 0;
}